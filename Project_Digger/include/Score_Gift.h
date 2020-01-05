#pragma once
#include "Gift.h"

class Score_Gift : public Gift
{
public:
	Score_Gift(sf::Sprite sprite);


	virtual void handle_collision(Data& m) override;

private:

};
