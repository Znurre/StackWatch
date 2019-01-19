#include "User.h"

QString User::displayName() const
{
	return m_displayName;
}

void User::setDisplayName(const QString &displayName)
{
	m_displayName = displayName;
}
