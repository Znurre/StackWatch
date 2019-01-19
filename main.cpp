#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "KeyValue.h"
#include "QStringEx.h"
#include "Key.h"

class RequestFactory
{
	public:
		RequestFactory(const QString &teamUrl, const QByteArray &accessToken)
			: m_baseUrl("https://api.stackexchange.com/2.2")
			, m_teamUrl(teamUrl)
			, m_accessToken(accessToken)
		{
		}

		template<typename ...TParameters>
		QNetworkRequest create(const QString &method, TParameters ...parameters)
		{
			const QStringList queryParameters =
			{
				// Method specific
				parameters...,

				// Default arguments
				api::team_url = m_teamUrl,
				api::site = QStringLiteral("stackoverflow"),
				api::key = QStringLiteral("u9eRD30bklGv9t9gzDRSAQ((")
			};

			const QString &query = queryParameters.join("&");
			const QStringList urlParts = { m_baseUrl, method, QStringEx::format("?%1", query) };
			const QString &url = urlParts.join("/");

			qDebug() << url << m_accessToken;

			QNetworkRequest request(url);
			request.setRawHeader("X-API-Access-Token", m_accessToken);

			return request;
		}

	private:
		QString m_baseUrl;
		QString m_teamUrl;
		QByteArray m_accessToken;
};

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	QSettings settings("settings.ini", QSettings::IniFormat);

	const QByteArray &access_token = settings
		.value("access_token")
		.toByteArray();

	const QString &team_url = settings
		.value("team_url")
		.toString();

	RequestFactory requestFactory(team_url, access_token);

	const QNetworkRequest &request = requestFactory.create("questions/unanswered");

	QNetworkAccessManager network;

	QNetworkReply *reply = network.get(request);

	QObject::connect(reply, &QNetworkReply::finished, [reply]
	{
		qDebug() << reply->readAll();
	});

	qDebug() << access_token << team_url;

	return application.exec();
}
