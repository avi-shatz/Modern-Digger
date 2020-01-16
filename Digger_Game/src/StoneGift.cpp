#include "StoneGift.h"

StoneGift::StoneGift(const sf::Vector2f position)
{
	setSprite(position);
}

void StoneGift::eatWithUpdate(Data& data)
{
	data.incStonesLeft(2);
	eat();
}

void StoneGift::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getStoneGift());
	m_sprite.setScale({ 0.1f, 0.1f });
	m_sprite.setPosition(position);
}
