#include "Diamond.h"


Diamond::Diamond(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void Diamond::eatWithUpdate(Data& data)
{
	eat();
	data.decDiamondsAmount();
	data.setScore(data.getScore() + 10);
}


void Diamond::setSprite(const Resources& res, const sf::Vector2f position)
{
	m_sprite.setTexture(res.getDiamond());
	m_sprite.setScale({ 0.12f, 0.14f });
	m_sprite.setPosition({ position.x + 6, position.y + 6 });
}

