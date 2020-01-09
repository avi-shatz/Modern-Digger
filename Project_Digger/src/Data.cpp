#include "Data.h"


Data::Data()
{
}

void Data::draw()
{
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
	m_score += 200;
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
