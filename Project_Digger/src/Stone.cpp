#include "Stone.h"


Stone::Stone(sf::Sprite sprite)
	:Edible_Object(sprite)
{
}

void Stone::handle_collision(Data& data, Movable_Object* obj_ptr)
{
	if (dynamic_cast<Digger*> (obj_ptr))
	{
		eat();
		data.set_stones_left(data.get_stones_left()-1);
	}
}
