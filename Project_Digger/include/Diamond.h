#pragma once
#include "Edible_Object.h"


class Diamond : public Edible_Object
{
public:
	Diamond(sf::Sprite sprite);

	virtual void handle_collision(Data& data, Movable_Object* obj_ptr) override;

private:

};
