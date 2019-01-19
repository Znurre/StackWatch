#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QDateTime>
#include <QJsonSerializer>

class User;

class Question : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int creation_date READ creationDate WRITE setCreationDate)

	Q_PROPERTY(QString link READ link WRITE setLink)
	Q_PROPERTY(QString title READ title WRITE setTitle)

	Q_PROPERTY(User *owner READ owner WRITE setOwner)

	public:
		Q_INVOKABLE Question();
		~Question();

		int creationDate() const;
		void setCreationDate(int creationDate);

		QString link() const;
		void setLink(const QString &link);

		QString title() const;
		void setTitle(const QString &title);

		User *owner() const;
		void setOwner(User *owner);

	private:
		int m_creationDate;

		QString m_link;
		QString m_title;

		User *m_owner;
};

Q_DECLARE_METATYPE(Question *)
Q_DECLARE_METATYPE(Array<Question *>)

#endif // QUESTION_H
