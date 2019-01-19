#include "KeyValue.h"
#include "QStringEx.h"

namespace api
{
	KeyValue::KeyValue(const QString &name, const QString &value)
		: m_name(name)
		, m_value(value)
	{
	}

	api::KeyValue::operator QString() const
	{
		const QByteArray &encoded = m_value
			.toUtf8()
			.toPercentEncoding();

		return QStringEx::format("%1=%2", m_name, encoded);
	}
}
