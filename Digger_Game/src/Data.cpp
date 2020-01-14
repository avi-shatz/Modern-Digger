#include "Data.h"


Data::Data()
{
	
	m_font.loadFromFile(FONT_PATH);

	m_livesTextOut.setFont(m_font);
	m_livesTextOut.setString(TXT_LIVES);
	m_livesTextOut.setColor(TXT_COLOR_DARK);
	m_livesTextOut.setPosition({ 0 + TXT_SHORT_SPACE, 0 });

	//make all fonts same.
	m_diamondsTextIn = m_diamondsTextOut = m_levelTextIn
		= m_levelTextOut = m_stonesTextIn = m_stonesTextOut
		= m_livesTextIn = m_livesTextOut;
		

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
}

void Data::draw(sf::RenderWindow& window)
{
	m_livesTextIn.setString(std::to_string(m_lives));
	m_stonesTextIn.setString(std::to_string(m_stonesLeft));
	m_levelTextIn.setString(std::to_string(m_level));
	m_diamondsTextIn.setString(std::to_string(m_diamonds_amount));

	window.draw(m_livesTextOut);
	window.draw(m_livesTextIn);

	window.draw(m_stonesTextOut);
	window.draw(m_stonesTextIn);

	window.draw(m_levelTextOut);
	window.draw(m_levelTextIn);	
	
	window.draw(m_diamondsTextOut);
	window.draw(m_diamondsTextIn);
}

void Data::resetLevel()
{
	m_stonesLeft = m_allowedStones;
	m_diamonds_amount = 0;
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

int Data::getTime() const
{
	return m_time;
}

int Data::getDiamondsAmount() const
{
	return m_diamonds_amount;
}


//-------------  setters  ---------------------------------------

void Data::setLives(int lives)
{
	m_lives = lives;
}

void Data::setScore(int score)
{
	m_score = score;
}

void Data::decStonesLeft()
{
	m_stonesLeft--;
}

void Data::setAllowedStones(int allowedStones)
{
	m_allowedStones = allowedStones;
}

void Data::incLevel()
{
	m_level++;
	//if advanced level add 200 to score.
	setScore(m_score+200);
}

void Data::setTime(int time)
{
	m_time = time;
}

void Data::incDiamondsAmount()
{
	m_diamonds_amount++;
}

void Data::decDiamondsAmount()
{
	m_diamonds_amount--;
}
