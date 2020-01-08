#include "Monster.h"


Monster::Monster(sf::Sprite sprite)
	:Movable_Object(sprite), m_direction((Dir)random_generator(1, 4))
{
}

void Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle)
{
}
