#pragma once
#include "Gift.h"

class TimeGift : public Gift
{
public:
	TimeGift(const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
    void setSprite(const sf::Vector2f position);

};
