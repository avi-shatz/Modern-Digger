#include "LivesGift.h"


LivesGift::LivesGift(const sf::Vector2f position)
{
	setSprite(position);
}

void LivesGift::eatWithUpdate(Data& data)
{
	data.incLives();
	eat();
}


void LivesGift::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getHeart2());
	m_sprite.setScale({ 0.04f, 0.04f });
	m_sprite.setPosition(position);
}
