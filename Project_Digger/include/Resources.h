#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"

class Resources 
{
public:
	Resources();

	//perpuosly did not put const in those function,
	//becouse the return of a non const varible by reference.
	sf::Sprite get_monster_sprite(sf::Vector2f position)const;
	sf::Sprite get_digger_sprite(sf::Vector2f position)const;
	sf::Sprite get_diamond_sprite(sf::Vector2f position)const;
	sf::Sprite get_wall_sprite(sf::Vector2f position)const;
	sf::Sprite get_stones_sprite(sf::Vector2f position)const;


private:

	sf::Texture m_monster;
	sf::Texture m_digger;
	sf::Texture m_diamond;
	sf::Texture m_wall;
	sf::Texture m_stones;
};