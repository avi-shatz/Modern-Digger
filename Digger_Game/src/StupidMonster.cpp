#include "StupidMonster.h"
#include "EdibleObject.h"
#include <Controller.h>

#include "Stone.h"

StupidMonster::StupidMonster(const sf::Vector2f position)
    :Monster(position)
{
    setSprite(position);
}

void StupidMonster::move(float deltaTime, Controller& controller)
{
    float pixMove = deltaTime * MONSTER_SPEED;
    

    while (true) {

        sf::Vector2f prevPosition = m_sprite.getPosition();

        MovableObject::move(pixMove, controller);

        if (!controller.handleMovement(*this))
        {
            m_sprite.setPosition(prevPosition); 
            m_direction = (Dir)random_generator(1, 4);
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
