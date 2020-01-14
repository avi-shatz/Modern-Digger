#include "MovableObject.h"


#include "MovableObject.h"


MovableObject::MovableObject(const sf::Vector2f position)
	: m_startPosition(position)
{
}

void MovableObject::resetPosition()
{
	m_sprite.setPosition(m_startPosition);
}
