#include "Smart_Monster.h"
#include "Edible_Object.h"
#include "Stone.h"

Smart_Monster::Smart_Monster(sf::Sprite sprite)
	:Monster(sprite), m_chase_digger(true),
    m_search_width_first((bool)random_generator(0, 1))
{ 
}

void Smart_Monster::move(float pix_move, const Digger& digger, const std::vector<Wall*> wall_vec, const std::vector<Edible_Object*> ed_vec, const sf::RectangleShape rectangle)
{
    
    sf::Vector2f position = get_position();
    sf::Vector2f digger_position = digger.get_position();

    if (m_chase_digger &&
        abs(digger_position.x - position.x) < 300 &&
        abs(digger_position.y - position.y) < 300)
    { 
        if (m_search_width_first) 
        {
            if (digger_position.x - position.x < 1)
                m_direction = Dir::Left;
            else if (digger_position.x - position.x > 2)
                m_direction = Dir::Right;
            else if (digger_position.y < position.y)
                m_direction = Dir::Up;
            else
                m_direction = Dir::Down;
        }else
        {

            if (digger_position.y - position.y < 1)
                m_direction = Dir::Up;
            else if (digger_position.y - position.y > 2)
                m_direction = Dir::Down;
            else if (digger_position.x < position.x)
                m_direction = Dir::Left;
            else
                m_direction = Dir::Right;
        }

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
        if(!m_chase_digger &&
           is_valid_move(temp_position, wall_vec, ed_vec, rectangle))
        {
            m_chase_digger = true;
            movement = m_temp_move;
            break;
        }

        sf::Vector2f new_position = sf::Vector2f{ m_sprite.getPosition().x + movement.x , m_sprite.getPosition().y + movement.y };

        if (!is_valid_move(new_position, wall_vec, ed_vec, rectangle))
        {
            m_chase_digger = !m_chase_digger;
            m_temp_move = movement;
            auto rand = random_generator(1, 4);
            m_direction = (Dir)rand;
        }
        else
            break;
    }
	m_sprite.move(movement);

}

bool Smart_Monster::is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const std::vector<Edible_Object*> ed_vec, const sf::RectangleShape rectangle) const
{
    auto temp_monster = *this;
    temp_monster.m_sprite.setPosition(position);

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
        if(wall->intersects(temp_monster))
            return false;
    }

    for (auto& ed : ed_vec)
    {
        if (ed->intersects(temp_monster))
            if (dynamic_cast<Stone*> (ed))
                return false;
            else
                break;
    }
    return true;
}