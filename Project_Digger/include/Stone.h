#pragma once
#include "Edible_Object.h"

class Stone : public Edible_Object
{
public:
	Stone(sf::Sprite sprite);


	virtual void handle_collision(Data& m) override;

private:

};
