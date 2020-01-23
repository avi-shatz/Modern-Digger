#pragma once
#include "Object.h"
#include "Wall.h"
#include "utilities.h"

class Controller;

class MovableObject : public Object
{
public:
	MovableObject(const sf::Vector2f position);
	virtual ~MovableObject() = 0 {};

	virtual void move(float pixMove, Controller& controller) = 0;// maybe should have implementation
	void resetPosition();

protected:

	sf::Vector2f m_startPosition;
	Dir m_direction;
};
