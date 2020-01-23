#pragma once
#include "Monster.h"

class SmartMonster : public Monster
{
public:
	SmartMonster (const sf::Vector2f position);


	virtual void move(float deltaTime, Controller& controller) override;

private:
	void setSprite(const sf::Vector2f position);

	bool m_chaseDigger; // for passing on walls
	const bool m_searchWidthFirst; // for search direction priority

	Dir m_tempDir; // holds persu attempt,
								//to keep running after digger
};

