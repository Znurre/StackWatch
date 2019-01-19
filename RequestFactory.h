#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

#include <QString>
#include <QByteArray>
#include <QNetworkRequest>

#include "QStringEx.h"
#include "KeyValue.h"
#include "Key.h"

class RequestFactory
{
	public:
		RequestFactory(const QString &teamUrl, const QByteArray &accessToken);

		template<typename ...TParameters>
		QNetworkRequest create(const QString &method, TParameters ...parameters)
		{
			const QStringList queryParameters =
			{
				// Method specific
				parameters...,

				// Default arguments
				api::team = m_teamUrl,
				api::site = QStringLiteral("stackoverflow"),
				api::key = QStringLiteral("u9eRD30bklGv9t9gzDRSAQ((")
			};

			const QString &query = queryParameters.join("&");
			const QStringList urlParts = { m_baseUrl, method, QStringEx::format("?%1", query) };
			const QString &url = urlParts.join("/");

			QNetworkRequest request(url);
			request.setRawHeader("X-API-Access-Token", m_accessToken);

			return request;
		}

	private:
		QString m_baseUrl;
		QString m_teamUrl;

		QByteArray m_accessToken;
};

#endif // REQUESTFACTORY_H
