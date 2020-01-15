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
	changeSpriteDirection(movement);

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
	m_spriteR.setTexture(Resources::instance().getDiggerR());
	m_spriteR.setScale({ 0.04f, 0.04f });
	m_spriteR.setPosition(position);

	m_sprite = m_spriteF = m_spriteL = m_spriteR;

	m_spriteL.setTexture(Resources::instance().getDiggerL());

	m_spriteF.setTexture(Resources::instance().getDiggerF());
	m_spriteF.setScale({ 0.08f, 0.08 });
}

void Digger::changeSpriteDirection(sf::Vector2f movement)
{
	if (movement.y == 0) 
	{
		if (movement.x > 0 && m_sprite.getTexture() != &Resources::instance().getDiggerR())
		{
			m_sprite.setTexture(*m_spriteR.getTexture());
			m_sprite.setScale(m_spriteR.getScale());
		}
		else if (movement.x < 0 && m_sprite.getTexture() != &Resources::instance().getDiggerL())
		{
			m_sprite.setTexture(*m_spriteL.getTexture());
			m_sprite.setScale(m_spriteL.getScale());
		}
	}
	else if(movement.y != 0)
		if (m_sprite.getTexture() != &Resources::instance().getDiggerF())
		{
			m_sprite.setTexture(*m_spriteF.getTexture());
			m_sprite.setScale(m_spriteF.getScale());
		}

}
