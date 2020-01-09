#include "Diamond.h"


Diamond::Diamond(sf::Sprite sprite)
	:Edible_Object(sprite)
{
}

void Diamond::handle_collision(Data& data, Movable_Object* obj_ptr)
{
	if (dynamic_cast<Digger*> (obj_ptr))
	{
		eat();
		data.dec_diamonds_amount();
	}
}

