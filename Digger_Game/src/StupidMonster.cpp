#include "StupidMonster.h"
#include "EdibleObject.h"
#include <Controller.h>

#include "Stone.h"

StupidMonster::StupidMonster(const sf::Vector2f position)
    :Monster(position)
{
    setSprite(position);
}

void StupidMonster::move(float deltaTime)
{
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
        m_sprite.move(movement);

        if (!Controller::instance().handleMovement(*this))
        {
            m_sprite.setPosition(prevPosition);
            auto rand = random_generator(1, 4);
            m_direction = (Dir)rand;
        }
        else
            break;
    }
}

void StupidMonster::setSprite(const sf::Vector2f position)
{
    m_sprite.setTexture(Resources::instance().getStupidMonster());
    m_sprite.setScale({ 0.05f, 0.05f });
    m_sprite.setPosition(position);
}
