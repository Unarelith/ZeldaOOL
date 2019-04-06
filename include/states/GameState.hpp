/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:21:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "StatsBar.hpp"
#include "World.hpp"

class GameState : public gk::ApplicationState {
	public:
		GameState();

		void update() override;

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		StatsBar m_statsBar;

		World m_world;
};

#endif // GAMESTATE_HPP_
