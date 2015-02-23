/*
 * =====================================================================================
 *
 *       Filename:  MainState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/01/2015 11:42:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAINSTATE_HPP_
#define MAINSTATE_HPP_

#include "ApplicationState.hpp"
#include "Scene.hpp"
#include "StatsBar.hpp"

class MainState : public ApplicationState {
	public:
		MainState();
		
		void update();
		
		void render();
		
	protected:
		Scene m_scene;
		
		StatsBar m_statsBar;
};

#endif // MAINSTATE_HPP_
