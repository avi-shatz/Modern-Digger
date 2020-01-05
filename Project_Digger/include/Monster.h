#pragma once
#include "Movable_Object.h"
#include "utilities.h"
#include "Digger.h"


class Monster : public Movable_Object
{
public:
	Monster(sf::Sprite sprite);

	virtual void move(float pix_move,const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle);

private:

};
