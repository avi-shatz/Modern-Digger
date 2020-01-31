#pragma once
#include "controller.h"

const std::string STRSTATISTIC = "Top " + std::to_string(STATS_ARRAY) + " records:";
const std::string STRSCORS = "   Score: ";
const std::string STRLEVEL = "Level: ";	 

class Statistic
{
public:
	Statistic();
	~Statistic();
	void showFileStatistic();

private:	
	void readFileStatistic();
	void buildsStringOfStatistics();
	void createsVecOfStatistics();
	void draw();

	std::vector<sf::Text> m_vecStatistic;
	std::vector<std::string> m_vecInitStatistic;

	sf::Font m_Font;
	sf::Text m_textTitle;

	sf::Texture m_BackgroundText;
	sf::Sprite m_BackgroundSprite;

	sf::Texture m_BackText;
	sf::Sprite m_BackSprite;

    sf::RenderWindow m_Window;
};


