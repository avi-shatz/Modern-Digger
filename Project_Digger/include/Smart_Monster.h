#pragma once
#include "Monster.h"

class Smart_Monster : public Monster
{
public:
	Smart_Monster (sf::Sprite sprite);


	virtual void move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle) override;

private:
	bool is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle) const;
	bool m_chase_digger; // for passing on walls
	sf::Vector2f m_temp_move;
};

