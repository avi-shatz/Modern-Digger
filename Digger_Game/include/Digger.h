#pragma once
#include "MovableObject.h"

const float DIGGER_SPEED = 120;

class Digger : public MovableObject
{
public:
	Digger(const sf::Vector2f position);

	void move(sf::Vector2f movement);

	void setStartPosition(const sf::Vector2f position);

private:
	void setSprite(const sf::Vector2f position);
	void changeSpriteDirection(sf::Vector2f movement);

	sf::Sprite m_spriteL;
	sf::Sprite m_spriteR;
	sf::Sprite m_spriteF;
};

