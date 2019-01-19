#ifndef EMAILCLIENT_H
#define EMAILCLIENT_H

#include <QByteArray>

class Email;

class EmailClient
{
	public:
		EmailClient(const QByteArray &smtpServer
			, const QByteArray &smtpUsername
			, const QByteArray &smtpPassword
			);

		void send(const Email &email);

	private:
		QByteArray m_smtpServer;
		QByteArray m_smtpUsername;
		QByteArray m_smtpPassword;
};

#endif // EMAILCLIENT_H
