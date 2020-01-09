#include <Controller.h>
#include <iostream>
#include <sstream>
#include "utilities.h"
#include <experimental/vector>

Controller::Controller()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Digger Game"),
	m_res(), m_data(), m_ifs(FILE_PATH),
	m_digger(m_res.get_digger_sprite({ 0, 0 }))
{
	//m_window.setFramerateLimit(120);

	if (m_ifs.bad())
	{
		std::cerr << "file is not open" << std::endl;
		exit(1);
	}
}

void Controller::run()
{

	bool keep_playing = true;

	read_level();

	bool level_on = true;
	sf::Clock clock;


	while (level_on)
	{
		if (!m_data.get_lives())
		{
			m_window.close();
			end_game_announcement(LOSE_MASSAGE);
			return; // temparary
			//if player loose exit 2 loops (go back to menu)
			keep_playing = false;
			break;
		}

		if (!m_data.get_diamonds_amount())
		{
			m_window.close();
			end_game_announcement(WIN_MASSAGE);
			return;// temparary
			break;//if player finished exit 1 loop (go to next level)
		}
		if (!m_data.get_stones_left())
		{
			m_window.close();
			end_game_announcement(LOSE_MASSAGE);
			return;// temparary
			break;//if player finished exit 1 loop (go to next level)
		}
		draw();

		// Handle events
		sf::Event event;
		if (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				//exit program
				return;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{

				case sf::Keyboard::Escape:
					m_window.close();
					//exit program
					return;
				}
			}
		}

		float t = clock.restart().asSeconds();

		sf::Vector2f movement;
		bool move = true;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			movement = {0, -DIGGER_SPEED * t};
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movement = {0, DIGGER_SPEED * t};
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			movement = {DIGGER_SPEED * t, 0};
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			movement = {-DIGGER_SPEED * t, 0};
		}
		else
		{
			move = false;
		}

		if (move) 
		{
			m_digger.move(movement, m_wall_vec, m_rectangle);
			handle_digger_collision();
		}

		for (auto monster : m_monster_vec)
		{
			monster->move(MONSTER_SPEED * t, m_digger, m_wall_vec, m_edible_vec, m_rectangle);
			handle_monster_collision(monster);
		}

	}

}

void Controller::draw()
{
	m_window.clear(MENU_BACKGROUND);

	m_data.draw(m_window);
	m_window.draw(m_rectangle);

	for (auto edible : m_edible_vec)
	{
		edible->draw(m_window);
	}

	for (auto wall : m_wall_vec)
	{
		wall->draw(m_window);
	}

	m_digger.draw(m_window);

	for (auto monster : m_monster_vec)
	{
		monster->draw(m_window);
	}

	m_window.display();
}

bool Controller::read_level()
{

	std::string line;

	// if we reached the end of file finish the game.
	if (!std::getline(m_ifs, line)) {
		return false;
	}

	m_board.clear();

	// reading the first to numbers from file 
	auto istr = std::istringstream(line);
	int stones_left, seconds;
	istr >> m_rows >> m_columns >> stones_left >> seconds;

	m_data.set_stones_left(stones_left);
	float rec_width =  m_columns * OBJECT_WIDTH;
	float rec_height =  m_rows * OBJECT_HEIGHT;

	m_rectangle.setSize({ rec_width, rec_height });
	m_rectangle.setPosition({ (WINDOW_WIDTH - rec_width) / 2, DATA_HEIGHT });
	m_rectangle.setFillColor(RECTANGLE_COLOR_LIGHT);
	m_rectangle.setOutlineColor(LINE_COLOR);
	m_rectangle.setOutlineThickness(LINE_THICKNESS);

	// reading one level from file
	for (int i = 0; i < m_rows; i++) {

		std::getline(m_ifs, line);
		add_spaces_to_string(line);
		m_board.push_back(line);
	}

	//getting the empty line before next level
	std::getline(m_ifs, line);


	m_data.inc_level();

	init_level();

	draw();

	return true;
}

//-- adding spaces to string, to match string size with board size ---------

void Controller::init_level()
{
	/*for (auto str : m_board)
	{
		std::cout << str << std::endl;
	}*/

	for (int r = 0; r < m_rows; r++)
		for (int c = 0; c < m_columns; c++)
		{

			sf::Vector2f position{ m_rectangle.getPosition().x + c * OBJECT_WIDTH,
				m_rectangle.getPosition().y + r * OBJECT_HEIGHT };
			

			sf::Sprite sprite;
			char ch = m_board[r][c];

			switch (ch)
			{
			case SPACE:
				break;

			case DIGGER:
				m_digger.set_position(position);
				break;

			case MONSTER:
			{
				auto rand = random_generator(0, 1);

				if (rand == 0)
				{
					m_monster_vec.push_back(new Smart_Monster(m_res.get_smart_monster_sprite(position)));
				}
				else
				{
					m_monster_vec.push_back(new Stupid_Monster(m_res.get_stupid_monster_sprite(position)));
				}
			}
			break;

			case STONE:
				sprite = m_res.get_stones_sprite(position);
				m_edible_vec.push_back(new Stone(sprite));
				break;

			case WALL:
				sprite = m_res.get_wall_sprite(position);
				m_wall_vec.push_back(new Wall(sprite));
				break;

			case DIAMOND:
				sprite = m_res.get_diamond_sprite(position);
				m_edible_vec.push_back(new Diamond(sprite));
				m_data.set_diamonds_amount(m_data.get_diamonds_amount()+1);
				break;
			}
		}
}

void Controller::add_spaces_to_string(std::string& line)
{
	while (line.size() < m_columns)
		line += SPACE;
}

void Controller::handle_digger_collision()
{
	for (auto& edible : m_edible_vec)
	{
		if (m_digger.intersects(*edible))
			edible->handle_collision(m_data, &m_digger);
	}

	for (auto& edible : m_edible_vec)
	{
		if (edible->is_eaten()) 
		{
			delete edible;
			edible = nullptr;
		}	
	}

	std::experimental::erase_if(m_edible_vec, [](const auto& edible)
		{ return !edible; });

	/*std::experimental::erase_if(m_edible_vec, [](const auto& edible) 
		{ return edible->is_eaten();});*/
	
}

void Controller::handle_monster_collision(Monster* monster)
{
}

void end_game_announcement(std::string imaje)
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
}
