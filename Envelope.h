#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <QObject>
#include <QJsonSerializer>

#include "Question.h"

class Envelope : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<Question *> items READ items WRITE setItems)

	public:
		Q_INVOKABLE Envelope() = default;
		~Envelope();

		Array<Question *> items() const;
		void setItems(const Array<Question *> &items);

	private:
		Array<Question *> m_items;
};

#endif // ENVELOPE_H
