#include <QNetworkReply>
#include <QThread>

#include "Poller.h"
#include "Envelope.h"

Poller::Poller(const QByteArray &accessToken, const QString &teamUrl, QSettings &settings)
	: m_requestFactory(teamUrl, accessToken)
	, m_settings(settings)
{
}

void Poller::run(int fromDate)
{
	const QNetworkRequest &request = m_requestFactory
		.create("questions/unanswered"
			, api::fromdate = fromDate + 1
			, api::sort = QStringLiteral("creation")
		);

	qDebug() << request.url();

	QNetworkReply *reply = m_network.get(request);

	connect(reply, &QNetworkReply::finished, reply, [=]
	{
		finished(reply, fromDate);
	});
}

void Poller::finished(QNetworkReply *reply, int previousFromDate)
{
	Envelope envelope;

	m_serializer.deserialize(reply, &envelope);

	const Array<Question *> questions = envelope.items();

	if (questions.count() > 0)
	{
		emit newQuestionsAvailable(questions);

		const int fromDate = questions[0]->creationDate();

		m_settings.setValue("from_date", fromDate);
		m_settings.sync();

		QThread::sleep(60);

		run(fromDate);
	}
	else
	{
		QThread::sleep(60);

		run(previousFromDate);
	}

	reply->deleteLater();
}
