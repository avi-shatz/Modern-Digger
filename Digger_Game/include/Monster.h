#pragma once
#include "MovableObject.h"
#include "utilities.h"
#include "Digger.h"


const float MONSTER_SPEED = 50;

class Monster : public MovableObject
{
public:
	Monster(const sf::Vector2f position);
	//virtual ~Monster() = 0;

	virtual void move(float deltaTime) = 0; // maby should  implement some shared logic

protected:

	Dir m_direction;
};
