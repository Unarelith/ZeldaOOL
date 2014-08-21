/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:58:00
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

#include "State.hpp"

#include "StatsBar.hpp"
#include "MapManager.hpp"

class MapState : public State {
	public:
		MapState(State *parent = nullptr);
		~MapState();
		
		void update();
		
		void render();
		
		enum Mode {
			Normal,
			ScrollingLeft,
			ScrollingRight,
			ScrollingUp,
			ScrollingDown
		};
		
	private:
		Mode m_mode;
		
		sf::View m_mapView;
		
		Map *m_nextMap;
		u16 m_scrolled;
		
		StatsBar m_statsBar;
};

#endif // MAPSTATE_HPP_
