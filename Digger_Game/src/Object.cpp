#include "Object.h"

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool Object::intersects(const Object& obj) const
{
	return getRec().intersects(obj.getRec());
}

void Object::setPosition(const sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f Object::getPosition()const
{
	return m_sprite.getPosition();
}

sf::FloatRect Object::getRec()const
{
	return m_sprite.getGlobalBounds();
}


