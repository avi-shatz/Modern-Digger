#include "Stupid_Monster.h"

Stupid_Monster::Stupid_Monster(sf::Sprite sprite)
	: Monster(sprite)
{
}

void Stupid_Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle)
{
	
    /*if (rand > 3)
        if(rand > 10)
            rand = 2;
        else
            rand = 1;*/
    
    

    sf::Vector2f movement;

    while (true) {
        switch (m_direction)
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

        sf::Vector2f new_position = sf::Vector2f{ m_sprite.getPosition().x + movement.x , m_sprite.getPosition().y + movement.y };
        if (!is_valid_move(new_position, wall_vec, rectangle))
        {
            auto rand = random_generator(1, 4);
            m_direction = (Dir)rand;
        }
        else
            break;
    }
	m_sprite.move(movement);
}

bool Stupid_Monster::is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle) const
{
    float height = m_sprite.getGlobalBounds().height;
    float width = m_sprite.getGlobalBounds().width;

    sf::Vector2f position2 = { position.x + width, position.y };
    sf::Vector2f position3 = { position.x, position.y + height };
    sf::Vector2f position4 = { position.x + width, position.y + height };

    if (!rectangle.getGlobalBounds().contains(position))
        return false;
    if (!rectangle.getGlobalBounds().contains(position2))
        return false;
    if (!rectangle.getGlobalBounds().contains(position3))
        return false;
    if (!rectangle.getGlobalBounds().contains(position4))
        return false;

    for (auto& wall : wall_vec)
    {
        if (wall->contains(position))
            return false;
        if (wall->contains(position2))
            return false;
        if (wall->contains(position3))
            return false;
        if (wall->contains(position4))
            return false;
    }

    return true;
}
