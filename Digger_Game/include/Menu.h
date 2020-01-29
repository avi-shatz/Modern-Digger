#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "controller.h"
#include "Statistic.h"

const sf::String STRINGSTART = { "PLAY" };
const sf::String STRINGCLOSE = { "EXIT" };
const sf::String STRINGSTATISTIC = { "STATISTIC" };

class Menu
{
public:
	Menu();

	void Run();
	

private:	
	// draw the all images of the Background
	void draw();
	// create the message of the Background
	void CreateMessage();
	// create the digger image of the Background
	void CreateDigger();
	// create the signs image of the Background
	void CreateSign();
	
	void CreateButterfly();
		
	void updateBigButton(sf::Vector2f position);
	void updateButton(sf::Sprite* button);

	sf::RenderWindow m_window;
	// for the images in the Background
	sf::Texture m_TextBackground;
	sf::Sprite m_SpriteBackground;
	sf::Texture m_TextDigger;
	sf::Sprite m_SpriteDigger;
	sf::Texture m_Textbutterfly;
	sf::Sprite m_SpriteButterfly;

	// for the  in the Background
	sf::Texture m_TextStart;	
	sf::Texture m_TextClose;	
	sf::Texture m_TextStatistic;

	sf::Sprite m_SpriteStart;
	sf::Sprite m_SpriteClose;
	sf::Sprite m_SpriteStatistic;

	sf::Sprite* m_bigButton;

	// for the messages in the Background
	sf::Text m_Startmessage;
	sf::Text m_Closemessage;
	sf::Text m_Statisticmessage;

	//for the song in the Background
	sf::SoundBuffer m_Buffer;
	sf::Sound m_sound;
	sf::Font m_Font;
};