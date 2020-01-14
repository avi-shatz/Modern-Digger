#pragma once
#include "Object.h"
#include "Wall.h"


class MovableObject : public Object
{
public:
	MovableObject(const sf::Vector2f position);
	//virtual ~MovableObject() = 0 {};

	void resetPosition();

protected:

	sf::Vector2f m_startPosition;
};
