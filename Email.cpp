#include "Email.h"

Email::Email(const QByteArray &from, const QByteArray &subject)
	: m_subject(quickmail_create(from, subject))
{
}

Email::~Email()
{
	quickmail_destroy(m_subject);
}

void Email::setTo(const QStringList &recipients)
{
	for (const QString &recipient : recipients)
	{
		quickmail_add_to(m_subject, recipient.toUtf8());
	}
}

void Email::setBody(const QString &body)
{
	QByteArray data = body.toLatin1();

	quickmail_add_body_memory(m_subject, "text/html", data.data(), data.length(), 0);
}
