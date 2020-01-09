#pragma once
#include "Gift.h"

class Time_Gift : public Gift
{
public:
	Time_Gift(sf::Sprite sprite);

	virtual void handle_collision(Data& data, Movable_Object* obj_ptr) override;

private:

};
