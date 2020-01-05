#include "Resources.h"

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

sf::Sprite Resources::get_monster_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_monster);
	sprite.setScale({ 0.05, 0.05 });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_digger_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_digger);
	sprite.setScale({ 0.04, 0.04 });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_diamond_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_diamond);
	sprite.setScale({ 0.1, 0.1 });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_wall_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_wall);
	sprite.setScale({ 0.123, 0.19 });
	sprite.setPosition(position);
	return sprite;
}

sf::Sprite Resources::get_stones_sprite(sf::Vector2f position)const
{
	sf::Sprite sprite(m_stones);
	sprite.setScale({ 0.1, 0.1 });
	sprite.setPosition(position);
	return sprite;
}
