#pragma once
#include "Object.h"
#include "Movable_Object.h"
#include "Data.h"

class Edible_Object : public Object
{
public:
	Edible_Object (sf::Sprite sprite);

	virtual void handle_collision(Data &m);
private:

};

