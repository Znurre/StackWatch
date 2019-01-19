#ifndef KEY_H
#define KEY_H

#include <QString>
#include <QStringBuilder>

#include "KeyValue.h"

namespace api
{
	class Key
	{
		public:
			Key(const char *name);

			KeyValue operator =(const QString &value) const;
			KeyValue operator =(const QByteArray &value) const;
			KeyValue operator =(int value) const;

		private:
			QString m_name;
	};

	const Key team_url("team_url");
	const Key site("site");
	const Key key("key");
}

#endif // KEY_H
