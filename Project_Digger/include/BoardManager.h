#pragma once
#include "Digger.h"
#include "constants.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class BoardManager {
public:
	BoardManager();
	~BoardManager();

	//reading one level of the game and update game caracters;
	bool read_level();

private:
	// adding spaces to string, for increasing string size to board size;
	void add_spaces_to_string(std::string& line, int columns);

	Digger m_digger;
	std::ifstream m_Ifs;  // holds board file 
	std::vector<std::string> m_starting_board;
	std::vector<std::string> m_current_board;

	int m_level;
	int m_score;
	int m_lives;
	int m_allowed_stones;
	int m_eaten_stones;
};