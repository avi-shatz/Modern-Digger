#include "Data.h"


Data::Data()
{
	
	m_font.loadFromFile(FONT_PATH);

	m_lives_text_out.setFont(m_font);
	m_lives_text_out.setString(TXT_LIVES);
	m_lives_text_out.setColor(TXT_COLOR_DARK);
	m_lives_text_out.setPosition({ 0 + TXT_SHORT_SPACE, 0 });

	//make all fonts same.
	m_diamonds_text_in = m_diamonds_text_out = m_level_text_in
		= m_level_text_out = m_stones_text_in = m_stones_text_out
		= m_lives_text_in = m_lives_text_out;
		

	//init rest of data text
	m_lives_text_in.setString("");
	m_lives_text_in.setPosition({TXT_LONG_SPACE + TXT_SHORT_SPACE, 0 });

	m_stones_text_out.setString(TXT_STONES);
	m_stones_text_out.setPosition({ TXT_LONG_SPACE + 2 * TXT_SHORT_SPACE, 0 });

	m_stones_text_in.setString("");
	m_stones_text_in.setPosition({ 3 * TXT_LONG_SPACE + 2 * TXT_SHORT_SPACE, 0 });

	m_level_text_out.setString(TXT_LEVEL);
	m_level_text_out.setPosition({ 3 * TXT_LONG_SPACE + 3 * TXT_SHORT_SPACE, 0 });

	m_level_text_in.setString("");
	m_level_text_in.setPosition({ 4 * TXT_LONG_SPACE + 3* TXT_SHORT_SPACE, 0 });

	m_diamonds_text_out.setString(TXT_DIAMONDS);
	m_diamonds_text_out.setPosition({ 4 * TXT_LONG_SPACE + 4 * TXT_SHORT_SPACE, 0 });

	m_diamonds_text_in.setString("");
	m_diamonds_text_in.setPosition({ 5.8f * TXT_LONG_SPACE + 4 * TXT_SHORT_SPACE, 0 });
}

void Data::draw(sf::RenderWindow& window)
{
	/*m_lives_text_in.setString(std::to_string(m_lives));
	m_stones_text_in.setString(std::to_string(m_stones_left));
	m_level_text_in.setString(std::to_string(m_level));
	m_diamonds_text_in.setString(std::to_string(m_diamonds_amount));*/

	/*window.draw(m_lives_text_out);
	window.draw(m_lives_text_in);

	window.draw(m_stones_text_out);
	window.draw(m_stones_text_in);

	window.draw(m_level_text_out);
	window.draw(m_level_text_in);	
	
	window.draw(m_diamonds_text_out);
	window.draw(m_diamonds_text_in);*/
}

//-------------  getters  ---------------------------------------

int Data::get_lives() const
{
	return m_lives;
}

int Data::get_score() const
{
	return m_score;
}

int Data::get_stones_left() const
{
	return m_stones_left;
}

int Data::get_level() const
{
	return m_level;
}

int Data::get_time() const
{
	return m_time;
}

int Data::get_diamonds_amount() const
{
	return m_diamonds_amount;
}


//-------------  setters  ---------------------------------------

void Data::set_lives(int lives)
{
	m_lives = lives;
}

void Data::set_score(int score)
{
	m_score = score;
}

void Data::set_stones_left(int stones_left)
{
	m_stones_left = stones_left;
}

void Data::inc_level()
{
	m_level++;
	//if advanced level add 200 to score.
	set_score(m_score+200);
}

void Data::set_time(int time)
{
	m_time = time;
}

void Data::set_diamonds_amount(int diamonds_amount)
{
	m_diamonds_amount = diamonds_amount;
}

void Data::dec_diamonds_amount()
{
	m_diamonds_amount--;
}
