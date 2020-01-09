#pragma once
#include "Gift.h"


class Stone_Gift : public Gift
{
public:
	Stone_Gift(sf::Sprite sprite);

	virtual void handle_collision(Data& data, Movable_Object* obj_ptr) override;

private:

};

