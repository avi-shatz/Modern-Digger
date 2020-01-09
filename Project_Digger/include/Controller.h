#pragma once
#include "BoardManager.h"
#include "WindowManager.h"
#include "Resources.h"
#include "Digger.h"
#include "Smart_Monster.h"
#include "Stupid_Monster.h"
#include "Stone.h"
#include "Wall.h"
#include "Diamond.h"
#include "Stone_Gift.h"
#include "Time_Gift.h"
#include "Score_Gift.h"
#include <fstream>
class Controller {
public:
	Controller();

	void run();

	void draw();
	bool read_level();
	
private:
	void init_level();
	void add_spaces_to_string(std::string& line);
	void handle_digger_collision();
	void handle_monster_collision(Monster* monster);

	sf::RenderWindow m_window;
	Resources m_res;
	Data m_data;
	std::fstream m_ifs;
	std::vector<std::string> m_board;
	sf::RectangleShape m_rectangle;

	Digger m_digger;
	std::vector<Monster*> m_monster_vec;
	std::vector<Edible_Object*> m_edible_vec;
	std::vector<Wall*> m_wall_vec;
	
	int m_rows = 0;
	int m_columns = 0;
};

void end_game_announcement(std::string imaje);