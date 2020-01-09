#pragma once
#include "constants.h"

class Data
{
public:
	Data();

	void draw(sf::RenderWindow& window);

	//getters
	int get_lives()const;
	int get_score()const;
	int get_stones_left()const;
	int get_level()const;
	int get_time()const;
	int get_diamonds_amount()const;

	//setters
	void set_lives(int lives);
	void set_score(int score);
	void set_stones_left(int stones_left);
	void inc_level();
	void set_time(int time);
	void set_diamonds_amount(int diamonds_amount);
	void dec_diamonds_amount();

private:

	int m_lives = LIVES;
	int m_score = 0;
	int m_stones_left = 0;
	int m_level = 0;
	int m_time = 0;
	int m_diamonds_amount = 0;

	sf::Text m_lives_text_in;
	sf::Text m_lives_text_out;
	sf::Text m_level_text_in;
	sf::Text m_level_text_out;
	sf::Text m_stones_text_in;
	sf::Text m_stones_text_out;
	sf::Text m_diamonds_text_in;
	sf::Text m_diamonds_text_out;
	sf::Font m_font;
};
