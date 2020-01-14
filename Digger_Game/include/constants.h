#pragma once
//constants file
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <thread>

const int LIVES = 3;


const std::string WINDOW_TITLE = "Digger Editor";
const std::string WIN_MASSAGE = "you_win_colorful.png";
const std::string LOSE_MASSAGE = "game_over.png";
const std::string FONT_PATH = "C:/Windows/Fonts/ahronbd.ttf";

//data
const std::string TXT_LIVES = "Lives: ";
const std::string TXT_STONES = "Stones Left: ";
const std::string TXT_TIME = "Time: ";
const std::string TXT_LEVEL = "Level: ";
const std::string TXT_SCORE = "Score: ";
const std::string TXT_DIAMONDS = "Diamonds: ";
const float TXT_SHORT_SPACE = 50;
const float TXT_LONG_SPACE = 90;

const std::string FILE_PATH = "Board.txt";
//const char FILE_PATH_CHAR_ARRAY[] = "board.txt";

//size
const int MAX_ROWS = 6;
const int MAX_COLUMMS = 15;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const float OBJECT_WIDTH = 80;
const float OBJECT_HEIGHT = 80;
const int DATA_HEIGHT = 50;
//const float RECTANGLE_SIZE = 130;
//const float BUTTON_SIZE = 110;
//const float BUTTON_SPACE = 30;

//ui
const sf::Color RECTANGLE_COLOR_LIGHT = sf::Color(246, 223, 227);
const sf::Color RECTANGLE_COLOR_DARK = sf::Color(255, 153, 204);
const sf::Color TXT_COLOR_DARK = sf::Color(67, 44, 135);
const sf::Color RECTANGLE_COLOR_NOT_ALLOWD = sf::Color(255, 102, 102);
const sf::Color LINE_COLOR = sf::Color(129, 13, 152);
const sf::Color MENU_BACKGROUND = sf::Color(229, 204, 255);
const float LINE_THICKNESS = 5;


// chars
const char WALL = '#';
const char MONSTER = '!';
const char DIAMOND = 'D';
const char STONE = '@';
const char DIGGER = '/';
const char SPACE = ' ';