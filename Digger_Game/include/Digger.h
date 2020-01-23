#pragma once
#include "MovableObject.h"

const float DIGGER_SPEED = 180;

class Digger : public MovableObject
{
public:
	Digger(const sf::Vector2f position);

	virtual void move(float deltaTime, Controller& controller) override;

	void setStartPosition(const sf::Vector2f position);

private:
	void setSprite(const sf::Vector2f position);
	void changeSpriteDirection();

	sf::Sprite m_spriteL;
	sf::Sprite m_spriteR;
	sf::Sprite m_spriteF;
};

