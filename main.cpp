#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

#include "Envelope.h"
#include "User.h"
#include "Poller.h"
#include "EmailComposer.h"

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	qRegisterMetaType<Envelope *>();
	qRegisterMetaType<Question *>();
	qRegisterMetaType<User *>();

	QSettings settings("settings.ini", QSettings::IniFormat);

	const QByteArray &accessToken = settings
		.value("access_token")
		.toByteArray();

	const QString &teamUrl = settings
		.value("team_url")
		.toString();

	const int fromDate = settings
		.value("from_date")
		.toInt();

	const QStringList &recipients = settings
		.value("recipients")
		.toStringList();

	const QByteArray &smtpServer = settings
		.value("smtp_server")
		.toByteArray();

	const QByteArray &smtpUsername = settings
		.value("smtp_username")
		.toByteArray();

	const QByteArray &smtpPassword = settings
		.value("smtp_password")
		.toByteArray();

	EmailComposer emailComposer(recipients
		, smtpServer
		, smtpUsername
		, smtpPassword
		);

	Poller poller(accessToken, teamUrl, settings);
	poller.run(fromDate);

	QObject::connect(&poller, &Poller::newQuestionsAvailable, &emailComposer, &EmailComposer::sendEmail);

	return application.exec();
}
