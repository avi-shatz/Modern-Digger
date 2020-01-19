#include "Data.h"
#include <iomanip>
#include <sstream>
#include "Resources.h"
#include <math.h> 

const std::string TXT_LIVES = "Lives: ";
const std::string TXT_STONES = "Stones Left: ";
const std::string TXT_TIME = "Time: ";
const std::string TXT_LEVEL = "Level: ";
const std::string TXT_SCORE = "Score: ";
const std::string TXT_DIAMONDS = "Diamonds: ";
const float TXT_SHORT_SPACE = 50;
const float TXT_LONG_SPACE = 90;

Data::Data()
{
	
	m_font.loadFromFile(FONT_PATH);
	
	m_livesTextOut.setFont(m_font);
	m_livesTextOut.setString(TXT_LIVES);
	m_livesTextOut.setColor(sf::Color::Yellow);
	m_livesTextOut.setPosition({ 0 + TXT_SHORT_SPACE, 0 });

	//make all fonts same.
	m_timeTextIn = m_timeTextOut = m_scoreTextOut =
		m_scoreTextIn = m_diamondsTextIn = m_diamondsTextOut =
		m_levelTextIn = m_levelTextOut = m_stonesTextIn = 
		m_stonesTextOut = m_livesTextIn = m_livesTextOut;
		

	//init rest of data text
	m_livesTextIn.setString("");
	m_livesTextIn.setPosition({TXT_LONG_SPACE + TXT_SHORT_SPACE, 0 });

	m_stonesTextOut.setString(TXT_STONES);
	m_stonesTextOut.setPosition({ TXT_LONG_SPACE + 2 * TXT_SHORT_SPACE, 0 });

	m_stonesTextIn.setString("");
	m_stonesTextIn.setPosition({ 3 * TXT_LONG_SPACE + 2 * TXT_SHORT_SPACE, 0 });

	m_levelTextOut.setString(TXT_LEVEL);
	m_levelTextOut.setPosition({ 3 * TXT_LONG_SPACE + 3 * TXT_SHORT_SPACE, 0 });

	m_levelTextIn.setString("");
	m_levelTextIn.setPosition({ 4 * TXT_LONG_SPACE + 3* TXT_SHORT_SPACE, 0 });

	m_diamondsTextOut.setString(TXT_DIAMONDS);
	m_diamondsTextOut.setPosition({ 4 * TXT_LONG_SPACE + 4 * TXT_SHORT_SPACE, 0 });

	m_diamondsTextIn.setString("");
	m_diamondsTextIn.setPosition({ 5.8f * TXT_LONG_SPACE + 4 * TXT_SHORT_SPACE, 0 });

	m_scoreTextOut.setString(TXT_SCORE);
	m_scoreTextOut.setPosition({ 5.8f * TXT_LONG_SPACE + 5 * TXT_SHORT_SPACE, 0 });

	m_scoreTextIn.setString("");
	m_scoreTextIn.setPosition({ 6.8f * TXT_LONG_SPACE + 5 * TXT_SHORT_SPACE, 0 });
	
	m_clockSprite.setTexture(Resources::instance().getClock());
	m_clockSprite.setPosition({ 7.8f * TXT_LONG_SPACE + 7 * TXT_SHORT_SPACE, 0 });
	m_clockSprite.scale(0.1f, 0.1f);

	/*m_timeTextOut.setString(TXT_TIME);
	m_timeTextOut.setPosition({ 6.8f * TXT_LONG_SPACE + 7 * TXT_SHORT_SPACE, 0 });*/

	m_timeTextIn.setString("");
	m_timeTextIn.setPosition({ 7.8f * TXT_LONG_SPACE + 8 * TXT_SHORT_SPACE, 0 });

	m_timeOut.setTexture(Resources::instance().getTimeOut());
	m_timeOut.setPosition(sf::Vector2f{ WINDOW_WIDTH/6, 0 });
	m_timeOut.setScale(0.1f, 0.1f);
	m_timeOut.setColor({ 255, 255, 255, 40 });
}

void Data::draw(sf::RenderWindow& window)
{
	m_livesTextIn.setString(std::to_string(m_lives));
	m_stonesTextIn.setString(std::to_string(m_stonesLeft));
	m_levelTextIn.setString(std::to_string(m_level));
	m_diamondsTextIn.setString(std::to_string(m_diamonds_amount));
	m_scoreTextIn.setString(std::to_string(m_score));

	float timeLeft = getTimeLeft();
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << timeLeft;

	m_timeTextIn.setString(stream.str());

	if(timeLeft < 10 && ((double)timeLeft - floor(timeLeft)) > 0.4   )
		window.draw(m_timeOut);

	window.draw(m_livesTextOut);
	window.draw(m_livesTextIn);

	window.draw(m_stonesTextOut);
	window.draw(m_stonesTextIn);

	window.draw(m_levelTextOut);
	window.draw(m_levelTextIn);	
	
	window.draw(m_diamondsTextOut);
	window.draw(m_diamondsTextIn);
	
	
	window.draw(m_scoreTextOut);
	window.draw(m_scoreTextIn);
	
	window.draw(m_clockSprite);
	//window.draw(m_timeTextOut);
	window.draw(m_timeTextIn);
}

void Data::resetLevel()
{
	m_stonesLeft = m_allowedStones;
	m_diamonds_amount = 0;
	m_time = 0;
	m_levelClock.restart();
}

//-------------  getters  ---------------------------------------

int Data::getLives() const
{
	return m_lives;
}

int Data::getScore() const
{
	return m_score;
}

int Data::getStonesLeft() const
{
	return m_stonesLeft;
}

int Data::getLevel() const
{
	return m_level;
}

float Data::getTimeLeft() const
{
	return m_time - m_levelClock.getElapsedTime().asSeconds();
}

int Data::getDiamondsAmount() const
{
	return m_diamonds_amount;
}


//-------------  setters  ---------------------------------------

void Data::incScore(int score)
{
	m_score += score;
}

void Data::decStonesLeft()
{
	m_stonesLeft--;
}

void Data::incStonesLeft(int num)
{
	m_stonesLeft += num;
}

void Data::setAllowedStones(int allowedStones)
{
	m_allowedStones = allowedStones;
}

void Data::incLevel()
{
	m_level++;
	//if advanced level add 200 to score.
	if (m_level > 1)
		incScore(153);
}

void Data::incTime(int time)
{
	m_time += time;
}

void Data::incDiamondsAmount()
{
	m_diamonds_amount++;
}

void Data::decDiamondsAmount()
{
	m_diamonds_amount--;
}

void Data::decLives(int lives)
{
	m_lives -= lives;
}

void Data::incLives(int lives)
{
	m_lives += lives;
}

void Data::restartClock()
{
	m_levelClock.restart();
}
