#pragma once
#include "Monster.h"

class StupidMonster : public Monster
{
public:
	StupidMonster(const sf::Vector2f position);

	virtual void move(float deltaTime, Controller& controller) override;

private:

   void setSprite(const sf::Vector2f position);

};
