#include "SmartMonster.h"
#include "EdibleObject.h"
#include "Controller.h"

SmartMonster::SmartMonster(const sf::Vector2f position)
	:Monster(position), m_chaseDigger(true),
    m_searchWidthFirst((bool)random_generator(0, 1))
{ 
    setSprite(position);
}

void SmartMonster::move(float deltaTime, Controller& controller)
{
    sf::Vector2f position = getPosition();
    sf::Vector2f digger_position = controller.getDiggerPosition();

    if (m_chaseDigger &&
        abs(digger_position.x - position.x) < 300 &&
        abs(digger_position.y - position.y) < 300)
    { 
        if (m_searchWidthFirst) 
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
        else
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

    while (true) {
        
        sf::Vector2f prevPosition = m_sprite.getPosition();

        if (!m_chaseDigger) 
        {
            Dir temp = m_direction;
            m_direction = m_tempDir;
            MovableObject::move(pixMove, controller);
            if (controller.handleMovement(*this))
            {
                m_chaseDigger = true;
                break;
            }
            else
            {
                m_sprite.setPosition(prevPosition);
                m_direction = temp;
            }
        }

        MovableObject::move(pixMove, controller);
        if (!controller.handleMovement(*this))
        {
            m_chaseDigger = !m_chaseDigger;
            if(!m_chaseDigger)
                m_tempDir = m_direction; // if cant chase save chase direction
            m_sprite.setPosition(prevPosition);
            m_direction = (Dir)random_generator(1, 4);
        }
        else
            break;
    }
}

void SmartMonster::setSprite(const sf::Vector2f position)
{
    m_sprite.setTexture(Resources::instance().getSmartMonster());
    m_sprite.setScale({ 0.07f, 0.07f });
    m_sprite.setPosition(position);
}
