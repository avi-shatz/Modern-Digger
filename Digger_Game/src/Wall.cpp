#include "Wall.h"


Wall::Wall(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void Wall::setSprite(const Resources& res, const sf::Vector2f position)
{
	m_sprite.setTexture(res.getWall());
	m_sprite.setScale({ 0.123f, 0.19f });
	m_sprite.setPosition(position);
}
