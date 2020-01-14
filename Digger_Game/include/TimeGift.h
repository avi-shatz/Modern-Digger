#pragma once
#include "Gift.h"

class TimeGift : public Gift
{
public:
	TimeGift(const Resources& res, const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
    void setSprite(const Resources& res, const sf::Vector2f position);

};
