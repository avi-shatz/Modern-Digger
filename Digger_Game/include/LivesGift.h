#pragma once
#include "Gift.h"

class LivesGift : public Gift
{
public:
	LivesGift(const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const sf::Vector2f position);

};
