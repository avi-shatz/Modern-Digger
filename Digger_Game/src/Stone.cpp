#include "Stone.h"


Stone::Stone(const sf::Vector2f position)
{
	setSprite(position);
}

void Stone::eatWithUpdate(Data& data)
{
	eat();
	data.incScore(25);
	data.decStonesLeft();
}

void Stone::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getStone());
	m_sprite.setScale({ 0.1f, 0.1f });
	m_sprite.setPosition(position);
}
