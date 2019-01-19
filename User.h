#ifndef USER_H
#define USER_H

#include <QObject>
#include <QJsonSerializer>

class User : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString display_name READ displayName WRITE setDisplayName)

	public:
		Q_INVOKABLE User() = default;

		QString displayName() const;
		void setDisplayName(const QString &displayName);

	private:
		QString m_displayName;
};

Q_DECLARE_METATYPE(User *)
Q_DECLARE_METATYPE(Array<User *>)

#endif // USER_H
