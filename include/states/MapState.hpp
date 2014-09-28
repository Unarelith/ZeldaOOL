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

#include "Dialog.hpp"
#include "GameState.hpp"
#include "MapManager.hpp"
#include "StatsBar.hpp"

class MapState : public GameState {
	public:
		MapState();
		~MapState();
		
		void scrollMaps(float vx, float vy);
		
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
		
		Map *m_nextMap;
		float m_scrolled;
		
		StatsBar m_statsBar;
		
		Dialog m_dialog;
};

#endif // MAPSTATE_HPP_
