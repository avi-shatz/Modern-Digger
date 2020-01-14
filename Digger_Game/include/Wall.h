#pragma once
#include "Object.h"


class Wall : public Object
{
public:
	Wall(const Resources& res, const sf::Vector2f position);

private:
	void setSprite(const Resources& res, const sf::Vector2f position);

};
