#include "Monster.h"


Monster::Monster(const sf::Vector2f position)
	:MovableObject(position), m_direction((Dir)random_generator(1, 4))
{
}

void Monster::move(float deltaTime)
{
}
