#include "Wall.h"


Wall::Wall(const sf::Vector2f position)
{
	setSprite(position);
}

void Wall::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getWall());
	m_sprite.setScale({ 0.123f, 0.19f });
	m_sprite.setPosition(position);
}
