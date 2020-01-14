#pragma once
#include "Gift.h"

class ScoreGift : public Gift
{
public:
	ScoreGift(const Resources& res, const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const Resources& res, const sf::Vector2f position);

};
