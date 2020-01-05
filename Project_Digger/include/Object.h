#pragma once
#include "constants.h"

class Object 
{
public:
	Object (sf::Sprite sprite);

	void draw(sf::RenderWindow& window);

	bool contains(const sf::Vector2f position) const;

	sf::Vector2f  get_position()const;

	void set_position(const sf::Vector2f position);

protected:
	sf::Sprite m_sprite;
};

