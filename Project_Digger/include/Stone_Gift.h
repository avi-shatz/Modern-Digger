#pragma once
#include "Gift.h"


class Stone_Gift : public Gift
{
public:
	Stone_Gift(sf::Sprite sprite);

	virtual void handle_collision(Data& m) override;

private:

};

