#include "ScoreGift.h"


ScoreGift::ScoreGift(const sf::Vector2f position)
{
	setSprite(position);
}

void ScoreGift::eatWithUpdate(Data& data)
{
	data.incScore(25);
	eat();
}

void ScoreGift::setSprite(const sf::Vector2f position)
{
	m_sprite.setTexture(Resources::instance().getDolar());
	m_sprite.setScale({ 0.116f, 0.116f });
	m_sprite.setPosition(position);
}
