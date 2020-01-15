#include <Controller.h>
#include <sstream>
#include "utilities.h"
#include <experimental/vector>

// declare and initialize static var outside of the class
//Controller Controller::m_instance = Controller();

Controller::Controller()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Digger Game"),
	m_res(Resources::instance()), m_data(), m_ifs(FILE_PATH),
	m_digger(m_res, {0,0}), m_levelTime()
{
	m_window.setFramerateLimit(90);

	if (m_ifs.bad()) {
		std::cerr << "coudn't open Board.txt" << std::endl;
		exit(EXIT_FAILURE);
	}
}

//----- returns controller instance -------
Controller& Controller::instance()
{
	static Controller instance;
	return instance;
}
  
//------  its controls the running of the game  ---------

void Controller::resetMovablePosition()
{
	m_digger.resetPosition();

	for (auto& monster : m_monsterVec)
	{
		monster->resetPosition();
	}
}

void Controller::run()
{
	bool win = false;
	bool keepPlaying = true;

	while (keepPlaying)
	{
		if (!readLevel())  {
			win = true;
			break;
		}

		sf::Clock clock;

		while (levelOn(keepPlaying))
		{
			draw();

			float deltaTime = clock.restart().asSeconds();
		
			for (auto& monster : m_monsterVec)
			{
				monster->move(deltaTime);
			}

			//handel user input and calls digger.move() accordingly
			processEvents(deltaTime);
			handlePlayerDeath();
		}
	}

	m_window.close();

	if(win)
		endGameAnnouncement(WIN_MASSAGE);
	else
		endGameAnnouncement(LOSE_MASSAGE);
}

sf::Vector2f Controller::getDiggerPosition()
{
	return m_digger.getPosition();
}

//----- check if level ended  -------

void Controller::handlePlayerDeath()
{
	for (auto& monster : m_monsterVec)
	{
		if (monster->intersects(m_digger))
		{
			m_data.decLives();
			resetMovablePosition();
			break;
		}
	}
}

bool Controller::levelOn(bool& keepPlaying)
{
	if (!m_data.getLives())
	{
		//if player loose exit 2 loops (go back to menu)
		keepPlaying = false;
		return false;
	}

	if (!m_data.getDiamondsAmount())
		//if player finished exit 1 loop (go to next level)
		return false; 

	if (!m_data.getStonesLeft() || m_data.getTimeLeft() <= 0)
	{
		initLevel();
		m_data.decLives();
	}


	return true;
}

//----- reads events from the Keyboard  -------

void Controller::processEvents(float deltaTime)
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
			exit(EXIT_SUCCESS);
		}
	}


	sf::Vector2f movement;
	bool move = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement = { 0, -deltaTime };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement = { 0, deltaTime };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement = { deltaTime, 0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement = { -deltaTime, 0 };
	}
	else
	{
		move = false;
	}

	if (move)
	{
		m_digger.move(movement);

		std::experimental::erase_if(m_edibleVec, [](const auto& edible)
			{ return edible->is_eaten(); });
	}
}

//------   display every object on window  ------

void Controller::draw()
{
	m_window.clear(MENU_BACKGROUND);

	m_data.draw(m_window);
	m_window.draw(m_boardRect);

	for (const auto& edible : m_edibleVec)
		 edible->draw(m_window);
	
	for (const auto& wall : m_wallVec)
		 wall->draw(m_window);

	for (const auto& monster : m_monsterVec)
		 monster->draw(m_window);

	m_digger.draw(m_window);

	m_window.display();
}

//------ reads the next level if it does exist  ------

bool Controller::readLevel()
{
	std::string line;

	// if we reached the end of file finish the game.
	if (!std::getline(m_ifs, line)) {
		return false;
	}

	m_charBoard.clear();

	// reading the first to numbers from file 
	auto istr = std::istringstream(line);
	int allowedStones;
	istr >> m_rows >> m_columns >> allowedStones >> m_levelTime;

	m_data.setAllowedStones(allowedStones);
	
	float rec_width =  m_columns * OBJECT_WIDTH;
	float rec_height =  m_rows * OBJECT_HEIGHT;

	m_boardRect.setSize({ rec_width, rec_height });
	m_boardRect.setPosition({ (WINDOW_WIDTH - rec_width) / 2, DATA_HEIGHT });
	m_boardRect.setFillColor(RECTANGLE_COLOR_LIGHT);
	m_boardRect.setOutlineColor(LINE_COLOR);
	m_boardRect.setOutlineThickness(LINE_THICKNESS);

	// reading one level from file
	for (int i = 0; i < m_rows; i++) 
    {
		std::getline(m_ifs, line);
		add_spaces_to_string(line);
		m_charBoard.push_back(line);
	}

	//getting the empty line before next level
	std::getline(m_ifs, line);

	m_data.incLevel();

	initLevel();

	draw();

	return true;
}

//----- initialize every game object from m_charBoard  ---------

void Controller::initLevel()
{
	m_data.resetLevel();
	m_data.setTime(m_levelTime);

	m_edibleVec.clear();
	m_monsterVec.clear();
	m_wallVec.clear();

	int monsterCnt = 0; 

	for (int r = 0; r < m_rows; r++)
		for (int c = 0; c < m_columns; c++)
		{

			sf::Vector2f position{ m_boardRect.getPosition().x + c * OBJECT_WIDTH,
				m_boardRect.getPosition().y + r * OBJECT_HEIGHT };
			
			char ch = m_charBoard[r][c];

			switch (ch)
			{
			case SPACE:
				break;

			case DIGGER:
				m_digger.setStartPosition(position);// should also reset startingPosition.
				break;

			case MONSTER:
			    {
				monsterCnt++;
				// chose between smart and stupid monsters
				  
				  if (monsterCnt % 2 == 0)
					  m_monsterVec.push_back(std::make_unique<SmartMonster>(m_res, position));
				  else
					  m_monsterVec.push_back(std::make_unique<StupidMonster>(m_res, position));
			    }
			    break;

			case STONE:
				m_edibleVec.push_back(std::make_unique<Stone>(m_res, position));
				break;

			case WALL:
				m_wallVec.push_back(std::make_unique<Wall>(m_res, position));
				break;

			case DIAMOND:
				m_edibleVec.push_back(std::make_unique<Diamond>(m_res, position));
				m_data.incDiamondsAmount();
				break;
			}
		}
}



//-- adding spaces to string, to match string size with board size ---------

void Controller::add_spaces_to_string(std::string& line)
{
	while (line.size() < m_columns)
		line += SPACE;
}

bool Controller::handleMovement(const Digger& obj)
{
	if(!validMovement(obj))
		return false;

	for (auto& edible : m_edibleVec)
	{
		if (obj.intersects(*edible))
		{
			edible->eatWithUpdate(m_data);
			return true;
		}
	}
	return true;
}

bool Controller::handleMovement(const Monster& obj)
{
	if (!validMovement(obj))
		return false;

	for (auto& edible : m_edibleVec)
	{
		if (typeid(*edible) == typeid(Stone) && obj.intersects(*edible))
			return false;
	}

	return true;
}

bool Controller::validMovement(const Object& obj)
{

	for (auto& wall : m_wallVec)
	{
		if (obj.intersects(*wall))
		{
			return false;
		}
	}

	float height = obj.getRec().height;
	float width = obj.getRec().width;

	sf::Vector2f position = obj.getPosition();
	sf::Vector2f position2 = { position.x + width, position.y };
	sf::Vector2f position3 = { position.x, position.y + height };
	sf::Vector2f position4 = { position.x + width, position.y + height };

	if (!m_boardRect.getGlobalBounds().contains(position))
		return false;
	if (!m_boardRect.getGlobalBounds().contains(position2))
		return false;
	if (!m_boardRect.getGlobalBounds().contains(position3))
		return false;
	if (!m_boardRect.getGlobalBounds().contains(position4))
		return false;

	return true;
}

void endGameAnnouncement(std::string imaje)
{
	auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "winner");

	auto texture = sf::Texture() ;
	texture.loadFromFile(imaje);

	auto sprite = sf::Sprite(texture);
	sprite.setPosition(0, 0);
	sprite.scale({ 0.5f, 0.35f });

	// Handle events
	sf::Event event;
	while (window.waitEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			//exit program
			return;
		}
		window.clear(RECTANGLE_COLOR_LIGHT);
		window.draw(sprite);
		window.display();
	}

	window.close();
}
