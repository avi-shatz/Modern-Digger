#include "Monster.h"


Monster::Monster(sf::Sprite sprite)
	:Movable_Object(sprite)
{
}

void Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle)
{
}
