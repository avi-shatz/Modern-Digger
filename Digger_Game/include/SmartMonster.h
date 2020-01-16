#pragma once
#include "Monster.h"

class SmartMonster : public Monster
{
public:
	SmartMonster (const sf::Vector2f position);


	virtual void move(float deltaTime) override;

private:
	void setSprite(const sf::Vector2f position);

	bool m_chase_digger; // for passing on walls
	const bool m_search_width_first; // for search direction priority
	sf::Vector2f m_temp_move;
};

