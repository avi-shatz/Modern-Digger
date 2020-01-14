#include "ScoreGift.h"


ScoreGift::ScoreGift(const Resources& res, const sf::Vector2f position)
{
	setSprite(res, position);
}

void ScoreGift::eatWithUpdate(Data& data)
{
	eat();
}

void ScoreGift::setSprite(const Resources& res, const sf::Vector2f position)
{
}
