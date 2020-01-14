#include "Digger.h"
#include "Controller.h"

Digger::Digger(const Resources& res, const sf::Vector2f position)
	:MovableObject(position)
{
	setSprite(res, position);
}

	
void Digger::move(sf::Vector2f movement)
{
	sf::Vector2f prevPosition = m_sprite.getPosition();
	m_sprite.move(movement * DIGGER_SPEED);

	if (!Controller::instance().handleMovement(*this))
		m_sprite.setPosition(prevPosition); 
}

void Digger::setStartPosition(const sf::Vector2f position)
{
	m_sprite.setPosition(position);
	m_startPosition = position;
}

void Digger::setSprite(const Resources& res, const sf::Vector2f position)
{
	m_sprite.setTexture(res.getDigger());
	m_sprite.setScale({ 0.04f, 0.04f });
	m_sprite.setPosition(position);
}
