#pragma once
#include "Gift.h"


class StoneGift : public Gift
{
public:
	StoneGift(const Resources& res, const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const Resources& res, const sf::Vector2f position);

};

