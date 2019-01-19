#ifndef KEYVALUE_H
#define KEYVALUE_H

#include <QString>

namespace api
{
	class KeyValue
	{
		public:
			KeyValue(const QString &name, const QString &value);

			operator QString() const;

		private:
			QString m_name;
			QString m_value;
	};
}

#endif // KEYVALUE_H
