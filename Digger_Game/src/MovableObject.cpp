#include "MovableObject.h"

MovableObject::MovableObject(const sf::Vector2f position)
	: m_startPosition(position), m_direction((Dir)random_generator(1, 4))
{
}

void MovableObject::move(float pixMove, Controller& controller)
{
    sf::Vector2f movement;

    switch (m_direction)
    {

    case Dir::Up:
        movement = { 0, -pixMove };
        break;

    case  Dir::Down:
        movement = { 0, pixMove };
        break;

    case  Dir::Right:
        movement = { pixMove, 0 };
        break;

    case  Dir::Left:
        movement = { -pixMove, 0 };
        break;
    }

    m_sprite.move(movement);
}

void MovableObject::resetPosition()
{
	m_sprite.setPosition(m_startPosition);
}
