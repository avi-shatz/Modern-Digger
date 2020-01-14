#include "StoneGift.h"

StoneGift::StoneGift(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void StoneGift::eatWithUpdate(Data& data)
{
	eat();
}

void StoneGift::setSprite(const Resources& res, const sf::Vector2f position)
{
}
