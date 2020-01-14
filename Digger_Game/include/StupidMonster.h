#pragma once
#include "Monster.h"

class StupidMonster : public Monster
{
public:
	StupidMonster(const Resources& res, const sf::Vector2f position);

	virtual void move(float deltaTime) override;

private:

   void setSprite(const Resources& res, const sf::Vector2f position);

};
