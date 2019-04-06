/*
 * =====================================================================================
 *
 *       Filename:  MenuState.hpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:30:21
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENUSTATE_HPP_
#define MENUSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "Menu.hpp"
#include "StatsBar.hpp"

class MenuState : public gk::ApplicationState {
	public:
		void update() override;

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		StatsBar m_statsBar;

		Menu m_menu;
};

#endif // MENUSTATE_HPP_
