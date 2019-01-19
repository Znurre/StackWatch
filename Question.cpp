#include "Question.h"
#include "User.h"

Question::Question()
	: m_owner(nullptr)
{
}

Question::~Question()
{
	delete m_owner;
}

int Question::creationDate() const
{
	return m_creationDate;
}

void Question::setCreationDate(int creationDate)
{
	m_creationDate = creationDate;
}

QString Question::link() const
{
	return m_link;
}

void Question::setLink(const QString &link)
{
	m_link = link;
}

QString Question::title() const
{
	return m_title;
}

void Question::setTitle(const QString &title)
{
	m_title = title;
}

User *Question::owner() const
{
	return m_owner;
}

void Question::setOwner(User *user)
{
	m_owner = user;
}
