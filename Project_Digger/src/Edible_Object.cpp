#include "Edible_Object.h"

Edible_Object::Edible_Object(sf::Sprite sprite)
	:Object(sprite)
{
}

void Edible_Object::handle_collision(Data& data, Movable_Object* obj_ptr)
{
}

bool Edible_Object::is_eaten()const
{
	return m_eaten;
}

void Edible_Object::eat()
{
	m_eaten = true;
}
