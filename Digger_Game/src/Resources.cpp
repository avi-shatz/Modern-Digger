#include "Resources.h"

const std::string STUPID_MONSTER_IMAGE = "monster_image.png";
const std::string SMART_MONSTER_IMAGE = "monster_dragon.png";
const std::string DIGGER_LEFT_IMAGE = "digger_left_image.png";
const std::string DIGGER_RIGHT_IMAGE = "digger_right_image.png";
const std::string DIGGER_FRONT_IMAGE = "digger_front_image.png";
const std::string DIAMOND_IMAGE = "diamond_image.png";
const std::string WALL_IMAGE = "wall_brick_image.png";
const std::string STONE_IMAGE = "stone_image.png";
const std::string TIME_SAND_IMAGE = "time_sand.png";
const std::string DOLAR_IMAGE = "dolar_image.png";
//const std::string HEART_IMAGE = "heart.png";
const std::string STONE_GIFT_IMAGE = "stone_gift.png";
const std::string TIME_OUT_IMAGE = "time_out.png";

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
	
	m_timeSand = sf::Texture();
	m_timeSand.loadFromFile(TIME_SAND_IMAGE);
	
	m_timeOut = sf::Texture();
	m_timeOut.loadFromFile(TIME_OUT_IMAGE);
	
	m_dolar = sf::Texture();
	m_dolar.loadFromFile(DOLAR_IMAGE);
	
	m_stoneGift = sf::Texture();
	m_stoneGift.loadFromFile(STONE_GIFT_IMAGE);

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

const sf::Texture& Resources::getTimeSand() const
{return m_timeSand;}


const sf::Texture& Resources::getTimeOut() const
{return m_timeOut;}

const sf::Texture& Resources::getDolar() const
{return m_dolar;}

const sf::Texture& Resources::getStoneGift() const
{return m_stoneGift;}
