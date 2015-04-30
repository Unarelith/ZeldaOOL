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
		void update();
		
		void draw();
		
	private:
		StatsBar m_statsBar;
		
		Menu m_menu;
};

#endif // MENUSTATE_HPP_
