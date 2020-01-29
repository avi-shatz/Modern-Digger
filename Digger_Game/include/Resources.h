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
	const sf::Texture& getTimeSand()const;
	const sf::Texture& getTimeOut()const;
	const sf::Texture& getDolar()const;
	const sf::Texture& getStoneGift()const;
	const sf::Texture& getGameBackround()const;
	const sf::Texture& getClock()const;
	const sf::Texture& getHeart1()const;
	const sf::Texture& getHeart2()const;
	const sf::Texture& getMenuButton()const;
	const sf::Texture& getMenuBackground()const;


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
	sf::Texture m_timeSand;
	sf::Texture m_timeOut;
	sf::Texture m_dolar;
	sf::Texture m_stoneGift;
	sf::Texture m_gameBackround;
	sf::Texture m_clock;
	sf::Texture m_heart1;
	sf::Texture m_heart2;

	sf::Texture m_pauseBackground;

	sf::Texture m_menuButton;
	sf::Texture m_menuBackground;
	
};