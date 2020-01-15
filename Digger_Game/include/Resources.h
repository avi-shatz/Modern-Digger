#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"

class Resources 
{
public:
	static Resources& instance();
	
	const sf::Texture& getStupidMonster()const;
	const sf::Texture& getSmartMonster()const;
	const sf::Texture& getDiggerL()const;
	const sf::Texture& getDiggerR()const;
	const sf::Texture& getDiggerF()const;
	const sf::Texture& getDiamond()const;
	const sf::Texture& getWall()const;
	const sf::Texture& getStone()const;


private:
	Resources();

	sf::Texture m_stupidMonster;
	sf::Texture m_smartMonster;
	sf::Texture m_diggerL;
	sf::Texture m_diggerR;
	sf::Texture m_diggerF;
	sf::Texture m_diamond;
	sf::Texture m_wall;
	sf::Texture m_stone;
	
};