#include "Resources.h"

const std::string STUPID_MONSTER_IMAGE = "monster_image.png";
const std::string SMART_MONSTER_IMAGE = "monster_dragon.png";
const std::string DIGGER_IMAGE = "digger_image.png";
const std::string DIAMOND_IMAGE = "diamond_image.png";
const std::string WALL_IMAGE = "wall_brick_image.png";
const std::string STONE_IMAGE = "stone_image.png";

Resources::Resources()
{
	//initialize all textures

	m_stupidMonster = sf::Texture();
	m_stupidMonster.loadFromFile(STUPID_MONSTER_IMAGE);
	
	m_smartMonster = sf::Texture();
	m_smartMonster.loadFromFile(SMART_MONSTER_IMAGE);

	m_digger = sf::Texture();
	m_digger.loadFromFile(DIGGER_IMAGE);
	
	m_diamond = sf::Texture();
	m_diamond.loadFromFile(DIAMOND_IMAGE);

	m_wall = sf::Texture();
	m_wall.loadFromFile(WALL_IMAGE);

	m_stone = sf::Texture();
	m_stone.loadFromFile(STONE_IMAGE);

}

const sf::Texture& Resources::getStupidMonster()const
{return m_stupidMonster;}

const sf::Texture& Resources::getSmartMonster()const
{return m_smartMonster;}

const sf::Texture& Resources::getDigger()const
{return m_digger;}

const sf::Texture& Resources::getDiamond()const
{return m_diamond;}

const sf::Texture& Resources::getWall()const
{return m_wall;}

const sf::Texture& Resources::getStone()const
{return m_stone;}
