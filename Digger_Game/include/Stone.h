#pragma once
#include "EdibleObject.h"

class Stone : public EdibleObject
{
public:
	Stone(const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const sf::Vector2f position);

};
