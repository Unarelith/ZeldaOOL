/*
 * =====================================================================================
 *
 *       Filename:  TeleporterTransition.hpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 21:52:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERTRANSITION_HPP_
#define TELEPORTERTRANSITION_HPP_

#include <SFML/Graphics/RectangleShape.hpp>

#include "Direction.hpp"
#include "Map.hpp"
#include "Transition.hpp"

class TeleporterTransition : public Transition {
	public:
		TeleporterTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection);

		void update() override;

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		Map *m_nextMap;

		gk::Timer m_timer;

		sf::RectangleShape m_rect1;
		sf::RectangleShape m_rect2;

		sf::Color m_color;
};

#endif // TELEPORTERTRANSITION_HPP_
