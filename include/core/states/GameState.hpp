/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:21:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "ApplicationState.hpp"
#include "SceneObject.hpp"
#include "StatsBar.hpp"
#include "World.hpp"

class GameState : public ApplicationState {
	public:
		GameState();

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		StatsBar m_statsBar;

		World m_world;
};

#endif // GAMESTATE_HPP_
