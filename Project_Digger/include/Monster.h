#pragma once
#include "Movable_Object.h"
#include "utilities.h"
#include "Digger.h"
class Edible_Object;


class Monster : public Movable_Object
{
public:
	Monster(sf::Sprite sprite);

	virtual void move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const std::vector<Edible_Object*> ed_vec, const sf::RectangleShape rectangle);

protected:
	Dir m_direction;
};
