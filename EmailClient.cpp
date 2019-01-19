#include <quickmail.h>

#include "EmailClient.h"
#include "Email.h"

EmailClient::EmailClient(const QByteArray &smtpServer
	, const QByteArray &smtpUsername
	, const QByteArray &smtpPassword
	)
	: m_smtpServer(smtpServer)
	, m_smtpUsername(smtpUsername)
	, m_smtpPassword(smtpPassword)
{
	quickmail_initialize();
}

void EmailClient::send(const Email &email)
{
	const char *error = quickmail_send(email.m_subject, m_smtpServer, 26, m_smtpUsername, m_smtpPassword);

	if (error)
	{
		fprintf(stderr, "Error sending e-mail: %s\n", error);
	}
}
