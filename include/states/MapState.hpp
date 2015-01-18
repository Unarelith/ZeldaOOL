/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:21:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAPSTATE_HPP_
#define MAPSTATE_HPP_

#include "ApplicationState.hpp"
#include "StatsBar.hpp"

#include "Movable.hpp"

class MapState : public ApplicationState {
	public:
		MapState();
		
		void update();
		
		void render();
		
	protected:
		StatsBar m_statsBar;
};

#endif // MAPSTATE_HPP_
