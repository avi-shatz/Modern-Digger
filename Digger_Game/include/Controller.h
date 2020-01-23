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
	Controller();

	void run();

	bool handleMovement(const Digger& obj);
	bool handleMovement(const Monster& obj);
	bool validMovement(const Object& obj);
	sf::Vector2f getDiggerPosition();

private:
	void resetMovablePosition();
	void handlePlayerDeath();
	bool levelOn(bool& keepPlaying);
	void draw();
	void drawWithoutDisplay();
	bool readLevel();
	void initLevel();
	bool processEvents(float deltaTime);
	void addSpacesToString(std::string& line);

	bool pauseGame();
	void endGameAnnouncement(std::string imaje);
	sf::RenderWindow m_window;

	Data m_data; // holds game data that displays on top of window
	std::fstream m_fileLevel; // holds the file with all levels

	std::vector<std::string> m_charBoard;  // holds one level in a char form 
	sf::RectangleShape m_boardRect; // game graphic borders

	//graphic objects
	Digger m_digger;
	std::vector	<std::unique_ptr <Monster>> m_monsterVec;
	std::vector<std::unique_ptr <EdibleObject>> m_edibleVec;
	std::vector<std::unique_ptr <Wall>> m_wallVec;
	
	// level board size
	int m_rows = 0;
	int m_columns = 0;

	int m_levelTime; //holds initial time for the current level
};

