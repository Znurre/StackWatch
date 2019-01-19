#ifndef EMAILCOMPOSER_H
#define EMAILCOMPOSER_H

#include <grantlee/engine.h>

#include <QJsonSerializer>

#include "EmailClient.h"
#include "Question.h"

class EmailComposer : public QObject
{
	public:
		EmailComposer(const QStringList &recipients
			, const QByteArray &smtpServer
			, const QByteArray &smtpUsername
			, const QByteArray &smtpPassword
			);

		void sendEmail(const Array<Question *> &questions);

	private:
		Grantlee::Engine m_engine;

		QStringList m_recipients;

		EmailClient m_emailClient;
};

#endif // EMAILCOMPOSER_H
