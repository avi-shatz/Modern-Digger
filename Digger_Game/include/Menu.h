#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	// its draw the all images of the Background
	void draw();
	// its create the image of the Background
	void CreateBackground();
	// its create the message of the Background
	void CreateMessage();
	// its create the digger image of the Background
	void CreateDigger();
	// its create the signs image of the Background
	void CreateSign();
	sf::Texture& TextureSign(sf::Texture& texture);
	//
	void CreateButterfly();
		

	sf::RenderWindow m_window;
	// for the images in the Background
	sf::Texture m_TextBackground;
	sf::Sprite m_SpriteBackground;
	sf::Texture m_TextDigger;
	sf::Sprite m_SpriteDigger;
	sf::Texture m_Textbutterfly;
	sf::Sprite m_SpriteButterfly;

	// for the Signs in the Background
	sf::Texture m_TextStart;
	sf::Sprite m_SpriteStart;
	sf::Texture m_TextClose;
	sf::Sprite m_SpriteClose;
	sf::Texture m_TextStatistic;
	sf::Sprite m_SpriteStatistic;

	// for the messages in the Background
	sf::Text m_Startmessage;
	sf::Text m_Closemessage;
	sf::Text m_Statisticmessage;

	//for the song in the Background
	sf::SoundBuffer m_Buffer;
	sf::Sound m_sound;
	sf::Font m_Font;
};