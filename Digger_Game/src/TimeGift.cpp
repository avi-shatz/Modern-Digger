#include "TimeGift.h"


TimeGift::TimeGift(const sf::Vector2f position)
{
	setSprite(position);
}

void TimeGift::eatWithUpdate(Data& data)
{
	data.incTime(10);
	eat();
}


void TimeGift::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getClock());
	m_sprite.setScale({ 0.1f, 0.1f });
	m_sprite.setPosition(position);
}
