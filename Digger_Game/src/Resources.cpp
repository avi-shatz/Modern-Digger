#include "Resources.h"

const std::string STUPID_MONSTER_IMAGE = "monster_image.png";
const std::string SMART_MONSTER_IMAGE = "monster_dragon.png";
const std::string DIGGER_LEFT_IMAGE = "digger_left_image.png";
const std::string DIGGER_RIGHT_IMAGE = "digger_right_image.png";
const std::string DIGGER_FRONT_IMAGE = "digger_front_image.png";
const std::string DIAMOND_IMAGE = "diamond_image.png";
const std::string WALL_IMAGE = "wall_brick_image.png";
const std::string STONE_IMAGE = "stone_image.png";
const std::string DOLAR_IMAGE = "dolar_image.png";
const std::string STONE_GIFT_IMAGE = "stone_gift.png";
const std::string TIME_OUT_IMAGE = "time_out.png";
const std::string GAME_BACKROUND = "game_background.jpg";
const std::string CLOCK_IMAGE = "clock_image.png";
const std::string HEART_IMAGE_1 = "heart_image1.png";
const std::string HEART_IMAGE_2 = "heart_image2.png";
const std::string MENU_BUTTON_IMAGE = "Sign.png";
const std::string MENU_BACKGROUND_IMAGE = "ImageBackGround.png";

const std::string TOTACH_SOUND = "totach.wav";
const std::string START_SOUND = "start.wav";
const std::string EAT_SOUND = "eat_sound.wav";
const std::string LOOSER_SOUND = "eize_looser_sound.wav";
const std::string TIME_OUT_SOUND = "time_out_sound.wav";

Resources::Resources()
{
	//initialize all textures

	m_stupidMonster.loadFromFile(STUPID_MONSTER_IMAGE);
	
	m_smartMonster.loadFromFile(SMART_MONSTER_IMAGE);

	m_diggerL.loadFromFile(DIGGER_LEFT_IMAGE);
	
	m_diggerR.loadFromFile(DIGGER_RIGHT_IMAGE);
	
	m_diggerF.loadFromFile(DIGGER_FRONT_IMAGE);
	
	m_diamond.loadFromFile(DIAMOND_IMAGE);

	m_wall.loadFromFile(WALL_IMAGE);

	m_stone.loadFromFile(STONE_IMAGE);
		
	m_timeOut.loadFromFile(TIME_OUT_IMAGE);
	
	m_dolar.loadFromFile(DOLAR_IMAGE);
	
	m_stoneGift.loadFromFile(STONE_GIFT_IMAGE);

	m_gameBackround.loadFromFile(GAME_BACKROUND);

	m_clock.loadFromFile(CLOCK_IMAGE);

	m_heart1.loadFromFile(HEART_IMAGE_1);
	m_heart2.loadFromFile(HEART_IMAGE_2);

	m_menuButton.loadFromFile(MENU_BUTTON_IMAGE);
	m_pauseBackground.loadFromFile(MENU_BACKGROUND_IMAGE);

	m_menuBackground.loadFromFile(MENU_BACKGROUND_IMAGE);

	m_start.loadFromFile(START_SOUND);
	m_totach.loadFromFile(TOTACH_SOUND);
	m_eat.loadFromFile(EAT_SOUND);
	m_looser.loadFromFile(LOOSER_SOUND);
	m_timeOut.loadFromFile(TIME_OUT_SOUND);
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

const sf::Texture& Resources::getTimeOut() const
{return m_timeOut;}

const sf::Texture& Resources::getDolar() const
{return m_dolar;}

const sf::Texture& Resources::getStoneGift() const
{return m_stoneGift;}

const sf::Texture& Resources::getGameBackround() const
{return m_gameBackround;}

const sf::Texture& Resources::getClock() const
{return m_clock;}

const sf::Texture& Resources::getHeart1() const
{return m_heart1;}

const sf::Texture& Resources::getHeart2() const
{return m_heart2;}

const sf::Texture& Resources::getMenuButton() const
{return m_menuButton;}

const sf::Texture& Resources::getMenuBackground() const
{return m_menuBackground;}

const sf::SoundBuffer& Resources::getTotachBuffer() const
{
	return m_totach;
}

const sf::SoundBuffer& Resources::getStartBuffer() const
{
	return m_start;
}

const sf::SoundBuffer& Resources::getLooserBuffer() const
{
	return m_looser;
}

const sf::SoundBuffer& Resources::getEatBuffer() const
{
	return m_eat;
}

const sf::SoundBuffer& Resources::getTimeOutBuffer() const
{
	return m_time;
}


