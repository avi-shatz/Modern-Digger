#include "Resources.h"

Resources::Resources()
{
	m_stupid_monster = sf::Texture();
	m_stupid_monster.loadFromFile(MONSTER_IMAGE);
	
	m_smart_monster = sf::Texture();
	m_smart_monster.loadFromFile(SMART_MONSTER_IMAGE);

	m_digger = sf::Texture();
	m_digger.loadFromFile(DIGGER_IMAGE);
	
	m_diamond = sf::Texture();
	m_diamond.loadFromFile(DIAMOND_IMAGE);

	m_wall = sf::Texture();
	m_wall.loadFromFile(WALL_IMAGE);

	m_stones = sf::Texture();
	m_stones.loadFromFile(STONE_IMAGE);

}

sf::Sprite Resources::get_stupid_monster_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_stupid_monster);
	sprite.setScale({ 0.05f, 0.05f });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_smart_monster_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_smart_monster);
	sprite.setScale({ 0.08f, 0.08f });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_digger_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_digger);
	sprite.setScale({ 0.04f, 0.04f });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_diamond_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_diamond);
	sprite.setScale({ 0.12f, 0.14f });
	sprite.setPosition({ position.x+6, position.y+6});
	return sprite;
}

sf::Sprite Resources::get_wall_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_wall);
	sprite.setScale({ 0.123f, 0.19f });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_stones_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_stones);
	sprite.setScale({ 0.1f, 0.1f });
	sprite.setPosition(position);
	return sprite;
}
