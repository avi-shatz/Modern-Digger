#include "TimeGift.h"


TimeGift::TimeGift(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void TimeGift::eatWithUpdate(Data& data)
{
	eat();
}


void TimeGift::setSprite(const Resources& res, const sf::Vector2f position)
{
}
