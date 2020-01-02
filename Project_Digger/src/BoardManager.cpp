#include "BoardManager.h"


BoardManager::BoardManager()
{
	
}

BoardManager::~BoardManager()
{
	
}

bool BoardManager::read_level()
{
	std::string line;

	// if we reached the end of file finish the game.
	if (!std::getline(m_Ifs, line)) {
		return false;
	}

	m_level++;
	//if advanced level add 20 to score.
	if (m_level > 1)
	{
		m_score += 20;
	}

	int  rows, columns;
	// reading the first to numbers from file 
	auto istr = std::istringstream(line);
	istr >> rows >> columns >> m_allowed_stones;

	// reading one level from file
	for (int i = 0; i < rows; i++) {

		std::getline(m_Ifs, line);
		add_spaces_to_string(line, columns);
		m_starting_board.push_back(line);
	}

	//getting the empty line before next level
	std::getline(m_Ifs, line);

	//reset_board();

	return true;
}

// adding spaces to string, for increasing string size to board size;
void BoardManager::add_spaces_to_string(std::string& line, int columns)
{
	while (line.size() < columns)
	{
		line += SPACE;
	}
}
