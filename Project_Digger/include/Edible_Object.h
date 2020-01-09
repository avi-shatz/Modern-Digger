#pragma once
#include "Object.h"
#include "Movable_Object.h"
#include "Data.h"
#include "Stupid_Monster.h"
#include "Smart_Monster.h"
#include "Digger.h"

class Edible_Object : public Object
{
public:
	Edible_Object (sf::Sprite sprite);

	virtual void handle_collision(Data &m, Movable_Object* obj_ptr);
	bool is_eaten()const;
	void eat();

protected:
	bool  m_eaten = false;
};

