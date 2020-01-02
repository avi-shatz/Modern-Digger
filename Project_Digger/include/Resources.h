#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Resources 
{
public:
	Resources();

	//perpuosly did not put const in those function,
	//becouse the return of a non const varible by reference.
	sf::Texture & get_monster_texture();
	sf::Texture & get_digger_texture();
	sf::Texture & get_diamond_texture();
	sf::Texture & get_wall_texture();
	sf::Texture & get_stones_texture();
	sf::Texture & get_delete_texture();
	sf::Texture & get_save_texture();
	sf::Texture & get_new_texture();

private:

	sf::Texture m_monster;
	sf::Texture m_digger;
	sf::Texture m_diamond;
	sf::Texture m_wall;
	sf::Texture m_stones;
	sf::Texture m_delete;
	sf::Texture m_save;
	sf::Texture m_new;
};