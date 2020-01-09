#pragma once
#include "Object.h"
#include "Wall.h"


class Movable_Object : public Object
{
public:
	Movable_Object(sf::Sprite sprite);
	virtual ~Movable_Object() = default;

protected:

};
