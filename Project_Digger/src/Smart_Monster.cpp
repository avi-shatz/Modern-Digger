#include "Smart_Monster.h"


Smart_Monster::Smart_Monster(sf::Sprite sprite)
	:Monster(sprite)
{
}

void Smart_Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle)
{

	sf::Vector2f movement = {0, pix_move};
    Dir direction;
    sf::Vector2f position = get_position();
    sf::Vector2f digger_position = digger.get_position();

    if(digger_position.x - position.x < 1)
        direction = Dir::Left;
    else if(digger_position.x - position.x > 2)
        direction = Dir::Right;
    else if(digger_position.y < position.y)
        direction = Dir::Up;
    else 
        direction = Dir::Down;

    switch (direction)
    {

    case Dir::Up:
        movement = { 0, -pix_move };
        break;

    case  Dir::Down:
        movement = { 0, pix_move };
        break;

    case  Dir::Right:
        movement = { pix_move, 0 };
        break;

    case  Dir::Left:
        movement = { -pix_move, 0 };
        break;
    }
	m_sprite.move(movement);

}

bool Smart_Monster::is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle) const
{
	return true;
}
