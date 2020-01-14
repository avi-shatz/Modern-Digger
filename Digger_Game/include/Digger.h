#pragma once
#include "MovableObject.h"

const float DIGGER_SPEED = 120;

class Digger : public MovableObject
{
public:
	Digger(const Resources& res, const sf::Vector2f position);

	void move(sf::Vector2f movement);

	void setStartPosition(const sf::Vector2f position);

private:
	void setSprite(const Resources& res, const sf::Vector2f position);

};

