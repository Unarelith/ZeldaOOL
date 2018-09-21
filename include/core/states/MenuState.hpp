/*
 * =====================================================================================
 *
 *       Filename:  MenuState.hpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:30:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENUSTATE_HPP_
#define MENUSTATE_HPP_

#include "ApplicationState.hpp"
#include "Menu.hpp"
#include "StatsBar.hpp"

class MenuState : public ApplicationState {
	public:
		MenuState(SceneObject &player) : m_player(player) {}

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		StatsBar m_statsBar;

		Menu m_menu;

		SceneObject &m_player;
};

#endif // MENUSTATE_HPP_
