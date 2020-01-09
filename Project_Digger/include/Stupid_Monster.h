#pragma once
#include "Monster.h"

class Stupid_Monster : public Monster
{
public:
	Stupid_Monster(sf::Sprite sprite);

	virtual void move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const std::vector<Edible_Object*> ed_vec, const sf::RectangleShape rectangle) override;

private:
	bool is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const std::vector<Edible_Object*> ed_vec, const sf::RectangleShape rectangle) const;

};
