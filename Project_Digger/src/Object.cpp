#include "Object.h"

Object::Object(sf::Sprite sprite)
	:m_sprite(sprite)
{
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool Object::contains(const sf::Vector2f position)const
{
	return m_sprite.getGlobalBounds().contains(position);
}

bool Object::intersects(const Object& obj) const
{
	return get_rec().intersects(obj.get_rec());
}

sf::Vector2f Object::get_position()const
{
	return m_sprite.getPosition();
}

sf::FloatRect Object::get_rec()const
{
	return m_sprite.getGlobalBounds();
}

void Object::set_position(const sf::Vector2f position)
{
	m_sprite.setPosition(position);
}
