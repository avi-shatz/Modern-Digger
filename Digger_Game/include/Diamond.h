#pragma once
#include "EdibleObject.h"


class Diamond : public EdibleObject
{
public:
	Diamond(const Resources& res, const sf::Vector2f position);

	virtual void eatWithUpdate(Data& data) override;

private:
	void setSprite(const Resources& res, const sf::Vector2f position);
};
