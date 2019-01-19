#include <grantlee/context.h>
#include <quickmail.h>

#include <QBuffer>

#include "Email.h"
#include "EmailComposer.h"

#include "incbin.h"

INCBIN(Template, "template.html");

EmailComposer::EmailComposer(const QStringList &recipients
	, const QByteArray &smtpServer
	, const QByteArray &smtpUsername
	, const QByteArray &smtpPassword
	)
	: m_recipients(recipients)
	, m_emailClient(smtpServer, smtpUsername, smtpPassword)
{
}

void EmailComposer::sendEmail(const Array<Question *> &questions)
{
	Q_UNUSED(questions);

	QList<QVariant> data;

	for (Question *question : questions)
	{
		data << QVariant::fromValue(question);
	}

	const QString &templateContent = QString::fromLatin1((const char *)gTemplateData, gTemplateSize);

	const Grantlee::Template &bodyTemplate = m_engine
		.newTemplate(templateContent, "template");

	Grantlee::Context context;
	context.insert("questions", data);

	const QString &body = bodyTemplate->render(&context);

	Email email("faq@monitor.se", "New questions posted");
	email.setTo(m_recipients);
	email.setBody(body);

	m_emailClient.send(email);
}
