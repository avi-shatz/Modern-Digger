#include "Digger.h"

Digger::Digger(sf::Sprite sprite)
	:Movable_Object(sprite)
{
}

	
void Digger::move(sf::Vector2f movement, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle)
{
	sf::Vector2f new_position = sf::Vector2f{m_sprite.getPosition().x + movement.x , m_sprite.getPosition().y + movement.y };

	if(is_valid_move(new_position, wall_vec, m_rectangle))
		m_sprite.move(movement);
}

bool Digger::is_valid_move(const sf::Vector2f position, const std::vector<Wall*> wall_vec, const sf::RectangleShape m_rectangle) const
{
	

	float height = m_sprite.getGlobalBounds().height;
	float width = m_sprite.getGlobalBounds().width;

	sf::Vector2f position2 = { position.x + width, position.y };
	sf::Vector2f position3 = { position.x, position.y + height};
	sf::Vector2f position4 = { position.x + width, position.y + height };

	if (!m_rectangle.getGlobalBounds().contains(position))
		return false;
	if (!m_rectangle.getGlobalBounds().contains(position2))
		return false;
	if (!m_rectangle.getGlobalBounds().contains(position3))
		return false;
	if (!m_rectangle.getGlobalBounds().contains(position4))
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
