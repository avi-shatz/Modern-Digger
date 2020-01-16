#pragma once
#include "Object.h"


class Wall : public Object
{
public:
	Wall(const sf::Vector2f position);

private:
	void setSprite(const sf::Vector2f position);

};
