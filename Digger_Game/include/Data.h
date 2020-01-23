#pragma once
#include "constants.h"

class Data
{
public:
	Data();

	void draw(sf::RenderWindow& window);
	void resetLevel();
	void pauseOrPlayClock();

	//getters
	int getLives()const;
	int getScore()const;
	int getStonesLeft()const;
	int getLevel()const;
	float getTimeLeft()const;
	int getDiamondsAmount()const;

	//setters
	void incScore(int score);
	void decStonesLeft();
	void incStonesLeft(int num = 1);
	void setAllowedStones(int allowedStones);
	void incTime(int time);
	void incLevel();	
	void incDiamondsAmount();
	void decDiamondsAmount();
	void decLives(int lives = 1);
	void incLives(int lives = 1);
	void restartClock();

private:
	void initAllText();
	

	bool m_paused = false;
	int m_lives = LIVES;
	int m_level = 0;
	int m_score = 0;
	int m_stonesLeft = 0;
	int m_allowedStones = 0;
	float m_time = 0;
	float m_runTime = 0;
	int m_diamonds_amount = 0;

	sf::Clock m_levelClock;
	sf::Font m_font;

	sf::Text m_livesTextIn;
	sf::Text m_livesTextOut;
	sf::Text m_levelTextIn;
	sf::Text m_levelTextOut;
	sf::Text m_stonesTextIn;
	sf::Text m_stonesTextOut;
	sf::Text m_diamondsTextIn;
	sf::Text m_diamondsTextOut;
	sf::Text m_scoreTextIn;
	sf::Text m_scoreTextOut;
	sf::Text m_timeTextIn;
	sf::Text m_timeTextOut;
	
	sf::Sprite m_clockSprite;
	sf::Sprite m_timeOut;
};
