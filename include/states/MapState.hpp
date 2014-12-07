/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:22:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPSTATE_HPP_
#define MAPSTATE_HPP_

#include "ApplicationState.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "StatsBar.hpp"

class MapState : public ApplicationState {
	public:
		MapState();
		~MapState();
		
		void update();
		
		void draw();
		
	private:
		Player *m_link;
		StatsBar &m_statsBar;
};

#endif // MAPSTATE_HPP_
