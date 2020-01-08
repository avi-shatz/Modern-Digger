#include "Smart_Monster.h"


Smart_Monster::Smart_Monster(sf::Sprite sprite)
	:Monster(sprite), m_temp_direction(Dir::Non)
{ 
}

void Smart_Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle)
{
    
    sf::Vector2f position = get_position();
    sf::Vector2f digger_position = digger.get_position();

    if (m_temp_direction == Dir::Non &&
        abs(digger_position.x - position.x) < 300 &&
        abs(digger_position.y - position.y) < 300)
    { 
        if (digger_position.x - position.x < 1)
            m_direction = Dir::Left;
        else if (digger_position.x - position.x > 2)
            m_direction = Dir::Right;
        else if (digger_position.y < position.y)
            m_direction = Dir::Up;
        else
            m_direction = Dir::Down;
    }
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
        sf::Vector2f temp_position =
            sf::Vector2f{ m_sprite.getPosition().x + m_temp_move.x ,
                          m_sprite.getPosition().y + m_temp_move.y };
        if(m_temp_direction != Dir::Non && 
           is_valid_move(temp_position, wall_vec, rectangle))
        {
            m_temp_direction = Dir::Non;
            movement = m_temp_move;
            break;
        }

        sf::Vector2f new_position = sf::Vector2f{ m_sprite.getPosition().x + movement.x , m_sprite.getPosition().y + movement.y };

        if (!is_valid_move(new_position, wall_vec, rectangle))
        {
            m_temp_move = movement;
            m_temp_direction = m_direction;
            auto rand = random_generator(1, 4);
            m_direction = (Dir)rand;
        }
        else
            break;
    }
	m_sprite.move(movement);

}

bool Smart_Monster::is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape rectangle) const
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
