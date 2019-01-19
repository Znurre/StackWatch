#include "Envelope.h"

Envelope::~Envelope()
{
	qDeleteAll(m_items);
}

Array<Question *> Envelope::items() const
{
	return m_items;
}

void Envelope::setItems(const Array<Question *> &items)
{
	m_items = items;
}
