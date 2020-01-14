#include "SmartMonster.h"
#include "EdibleObject.h"
#include "Stone.h"
#include "Controller.h"

SmartMonster::SmartMonster(const Resources& res, const sf::Vector2f position)
	:Monster(position), m_chase_digger(true),
    m_search_width_first((bool)random_generator(0, 1))
{ 
    setSprite(res, position);
}

void SmartMonster::move(float deltaTime)
{
    
    sf::Vector2f position = getPosition();
    sf::Vector2f digger_position = Controller::instance().getDiggerPosition();

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

    float pixMove = deltaTime * MONSTER_SPEED;
    sf::Vector2f movement;

    while (true) {
        switch (m_direction)
        {

        case Dir::Up:
            movement = { 0, -pixMove };
            break;

        case  Dir::Down:
            movement = { 0, pixMove };
            break;

        case  Dir::Right:
            movement = { pixMove, 0 };
            break;

        case  Dir::Left:
            movement = { -pixMove, 0 };
            break;
        }
        
        sf::Vector2f prevPosition = m_sprite.getPosition();

        if (!m_chase_digger) 
        {
            m_sprite.move(m_temp_move);
            if (Controller::instance().handleMovement(*this))
            {
                m_chase_digger = true;
                break;
            }
            else
                m_sprite.setPosition(prevPosition);
        }

        m_sprite.move(movement);
        if (!Controller::instance().handleMovement(*this))
        {
            m_chase_digger = !m_chase_digger;
            if(!m_chase_digger)
                m_temp_move = movement; // if cant chase save chase movement
            m_sprite.setPosition(prevPosition);
            auto rand = random_generator(1, 4);
            m_direction = (Dir)rand;
        }
        else
            break;
    }
}

void SmartMonster::setSprite(const Resources& res, const sf::Vector2f position)
{
    m_sprite.setTexture(res.getSmartMonster());
    m_sprite.setScale({ 0.07f, 0.07f });
    m_sprite.setPosition(position);
}
