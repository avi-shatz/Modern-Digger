#include "Resources.h"
#include "constants.h"

Resources::Resources()
{
	m_monster = sf::Texture();
	m_monster.loadFromFile(MONSTER_IMAGE);

	m_digger = sf::Texture();
	m_digger.loadFromFile(DIGGER_IMAGE);
	
	m_diamond = sf::Texture();
	m_diamond.loadFromFile(DIAMOND_IMAGE);

	m_wall = sf::Texture();
	m_wall.loadFromFile(WALL_IMAGE);

	m_stones = sf::Texture();
	m_stones.loadFromFile(STONE_IMAGE);

}

sf::Texture & Resources::get_monster_texture()
{
	return m_monster;
}

sf::Texture & Resources::get_digger_texture()
{
	return m_digger;
}

sf::Texture& Resources::get_diamond_texture()
{
	return m_diamond;
}

sf::Texture& Resources::get_wall_texture()
{
	return m_wall;
}

sf::Texture& Resources::get_stones_texture()
{
	return m_stones;
}
