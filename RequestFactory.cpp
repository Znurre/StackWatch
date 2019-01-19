#include "RequestFactory.h"

RequestFactory::RequestFactory(const QString &teamUrl, const QByteArray &accessToken)
	: m_baseUrl("https://api.stackexchange.com/2.2")
	, m_teamUrl(teamUrl)
	, m_accessToken(accessToken)
{
}
