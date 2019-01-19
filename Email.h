#ifndef EMAIL_H
#define EMAIL_H

#include <quickmail.h>

#include <QByteArray>
#include <QStringList>

class Email
{
	friend class EmailClient;

	public:
		Email(const QByteArray &from, const QByteArray &subject);
		~Email();

		void setTo(const QStringList &recipients);
		void setBody(const QString &body);

	private:
		quickmail m_subject;
};

#endif // EMAIL_H
