#include "Stone.h"


Stone::Stone(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void Stone::eatWithUpdate(Data& data)
{
	eat();
	data.decStonesLeft();
}

void Stone::setSprite(const Resources& res, const sf::Vector2f position)
{
	m_sprite.setTexture(res.getStone());
	m_sprite.setScale({ 0.1f, 0.1f });
	m_sprite.setPosition(position);
}
