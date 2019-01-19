#ifndef POLLER_H
#define POLLER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QJsonSerializer>
#include <QSettings>

#include "RequestFactory.h"
#include "Question.h"

class Poller : public QObject
{
	Q_OBJECT

	public:
		Poller(const QByteArray &accessToken, const QString &teamUrl, QSettings &settings);

		void run(int fromDate);

	private:
		void finished(QNetworkReply *reply, int previousFromDate);

		RequestFactory m_requestFactory;

		QNetworkAccessManager m_network;
		QJsonSerializer m_serializer;
		QSettings &m_settings;

	signals:
		void newQuestionsAvailable(const Array<Question *> &questions);
};

#endif // POLLER_H
