#pragma once
#include "BoardManager.h"
#include "WindowManager.h"
#include "Resources.h"
#include "Digger.h"
#include "SmartMonster.h"
#include "StupidMonster.h"
#include "Stone.h"
#include "Wall.h"
#include "Diamond.h"
#include "StoneGift.h"
#include "TimeGift.h"
#include "LivesGift.h"
#include "ScoreGift.h"
#include <memory>
#include <fstream>
#include <iostream>

class Controller {
public:
	//Controller(Controller&) = delete; //delete copy constractor
	static Controller& instance();  // returns controller instance 

	void run();

	void resetMovablePosition();
	bool handleMovement(const Digger& obj);
	bool handleMovement(const Monster& obj);
	bool validMovement(const Object& obj);
	sf::Vector2f getDiggerPosition();

private:
	Controller();
	//Controller m_instance;

	void handlePlayerDeath();
	bool levelOn(bool& keepPlaying);
	void draw();
	bool readLevel();
	void initLevel();
	void processEvents(float deltaTime);
	void add_spaces_to_string(std::string& line);
	sf::RenderWindow m_window;

	Resources m_res; // holds all textures
	Data m_data; // holds game data that displays on top of window
	std::fstream m_ifs; // holds the file with all levels

	std::vector<std::string> m_charBoard;  // holds one level in a char form 
	sf::RectangleShape m_boardRect; // game graphic borders

	//graphic objects
	Digger m_digger;
	std::vector	<std::unique_ptr <Monster>> m_monsterVec;
	std::vector<std::unique_ptr <EdibleObject>> m_edibleVec;
	std::vector<std::unique_ptr <Wall>> m_wallVec;
	
	int m_levelTime;

	// level board size
	int m_rows = 0;
	int m_columns = 0;
};

void endGameAnnouncement(std::string imaje);