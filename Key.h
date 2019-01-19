#ifndef KEY_H
#define KEY_H

#include <QString>
#include <QStringBuilder>
#include <QDateTime>

#include "KeyValue.h"

namespace api
{
	class Key
	{
		public:
			Key(const char *name);

			KeyValue operator =(const QString &value) const;
			KeyValue operator =(const QByteArray &value) const;
			KeyValue operator =(const QDateTime &value) const;
			KeyValue operator =(int value) const;

		private:
			QString m_name;
	};

	const Key team("team");
	const Key site("site");
	const Key key("key");
	const Key fromdate("fromdate");
	const Key sort("sort");
	const Key order("order");
}

#endif // KEY_H
