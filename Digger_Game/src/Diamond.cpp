#include "Diamond.h"


Diamond::Diamond(const sf::Vector2f position)
{
	setSprite(position);
}

void Diamond::eatWithUpdate(Data& data)
{
	eat();
	data.decDiamondsAmount();
	data.incScore(10);
}


void Diamond::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getDiamond());
	m_sprite.setScale({ 0.12f, 0.14f });
	m_sprite.setPosition({ position.x + 6, position.y + 6 });
}

