#pragma once
#include "constants.h"
#include "Resources.h"
#include "Data.h"
#include <typeinfo>

class Object 
{
public:
	//virtual ~Object() = 0;
	void draw(sf::RenderWindow& window);

	//checks collision between two objects 
	bool intersects(const Object& obj) const;

	void setPosition(const sf::Vector2f position);
	sf::Vector2f  getPosition()const;
	sf::FloatRect getRec()const;

protected:
	

	sf::Sprite m_sprite;
};

