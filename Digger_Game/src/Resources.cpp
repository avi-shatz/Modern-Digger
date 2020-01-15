#include "Resources.h"

const std::string STUPID_MONSTER_IMAGE = "monster_image.png";
const std::string SMART_MONSTER_IMAGE = "monster_dragon.png";
const std::string DIGGER_LEFT_IMAGE = "digger_left_image.png";
const std::string DIGGER_RIGHT_IMAGE = "digger_right_image.png";
const std::string DIGGER_FRONT_IMAGE = "digger_front_image.png";
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

	m_diggerL = sf::Texture();
	m_diggerL.loadFromFile(DIGGER_LEFT_IMAGE);
	
	m_diggerR = sf::Texture();
	m_diggerR.loadFromFile(DIGGER_RIGHT_IMAGE);
	
	m_diggerF = sf::Texture();
	m_diggerF.loadFromFile(DIGGER_FRONT_IMAGE);
	
	m_diamond = sf::Texture();
	m_diamond.loadFromFile(DIAMOND_IMAGE);

	m_wall = sf::Texture();
	m_wall.loadFromFile(WALL_IMAGE);

	m_stone = sf::Texture();
	m_stone.loadFromFile(STONE_IMAGE);

}

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

const sf::Texture& Resources::getStupidMonster()const
{return m_stupidMonster;}

const sf::Texture& Resources::getSmartMonster()const
{return m_smartMonster;}

const sf::Texture& Resources::getDiggerL()const
{return m_diggerL;}

const sf::Texture& Resources::getDiggerR()const
{return m_diggerR;}

const sf::Texture& Resources::getDiggerF()const
{return m_diggerF;}

const sf::Texture& Resources::getDiamond()const
{return m_diamond;}

const sf::Texture& Resources::getWall()const
{return m_wall;}

const sf::Texture& Resources::getStone()const
{return m_stone;}
