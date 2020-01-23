#include "Digger.h"
#include "Controller.h"

Digger::Digger(const sf::Vector2f position)
	:MovableObject(position)
{
	setSprite(position);
}

	
void Digger::move(float deltaTime, Controller& controller)
{
	bool move = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = Dir::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = Dir::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = Dir::Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = Dir::Left;
	}
	else
	{
		move = false;
	}

	if (move)
	{
		sf::Vector2f prevPosition = m_sprite.getPosition();
		MovableObject::move(deltaTime * DIGGER_SPEED, controller);
		changeSpriteDirection();

		if (!controller.handleMovement(*this))
			m_sprite.setPosition(prevPosition);
	}
}

void Digger::setStartPosition(const sf::Vector2f position)
{
	m_sprite.setPosition(position);
	m_startPosition = position;
}

void Digger::setSprite(const sf::Vector2f position)
{
	m_spriteR.setTexture(Resources::instance().getDiggerR());
	m_spriteR.setScale({ 0.04f, 0.04f });
	m_spriteR.setPosition(position);

	m_sprite = m_spriteF = m_spriteL = m_spriteR;

	m_spriteL.setTexture(Resources::instance().getDiggerL());

	m_spriteF.setTexture(Resources::instance().getDiggerF());
	m_spriteF.setScale({ 0.08f, 0.08f });
}

void Digger::changeSpriteDirection()
{
		if (m_direction == Dir::Right &&
			m_sprite.getTexture() != m_spriteR.getTexture())
		{
			m_sprite.setTexture(*m_spriteR.getTexture());
		}
		else if (m_direction == Dir::Left &&
			m_sprite.getTexture() != m_spriteL.getTexture())
		{
			m_sprite.setTexture(*m_spriteL.getTexture());
		}
		else if ((m_direction == Dir::Up || m_direction == Dir::Down)
			&& m_sprite.getTexture() != m_spriteF.getTexture())
		{
			m_sprite.setTexture(*m_spriteF.getTexture());
		}
}
