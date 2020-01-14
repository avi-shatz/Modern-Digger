#include "EdibleObject.h"

bool EdibleObject::is_eaten()const
{
	return m_eaten;
}

void EdibleObject::eat()
{
	m_eaten = true;
}
