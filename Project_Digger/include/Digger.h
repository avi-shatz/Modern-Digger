#pragma once
#include "Movable_Object.h"

class Digger : public Movable_Object
{
public:
	Digger(sf::Sprite sprite);

	void move(sf::Vector2f movementconst, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle);
private:
	bool is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle) const;

};

