#pragma once
#include "Gift.h"


class StoneGift : public Gift
{
public:
	StoneGift(const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const sf::Vector2f position);

};

