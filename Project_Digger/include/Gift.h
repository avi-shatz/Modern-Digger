#pragma once
#include "Edible_Object.h"

class Gift : public Edible_Object
{
public:
	Gift(sf::Sprite sprite);

	virtual void handle_collision(Data& data, Movable_Object* obj_ptr) override;

private:

};
