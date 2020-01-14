#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"

class Resources 
{
public:
	Resources();

	
	const sf::Texture& getStupidMonster()const;
	const sf::Texture& getSmartMonster()const;
	const sf::Texture& getDigger()const;
	const sf::Texture& getDiamond()const;
	const sf::Texture& getWall()const;
	const sf::Texture& getStone()const;


private:

	sf::Texture m_stupidMonster;
	sf::Texture m_smartMonster;
	sf::Texture m_digger;
	sf::Texture m_diamond;
	sf::Texture m_wall;
	sf::Texture m_stone;
};