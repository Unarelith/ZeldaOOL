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

#include "Map.hpp"
#include "Sprite.hpp"

class MapState : public State {
	public:
		MapState(State *parent = nullptr);
		~MapState();
		
		void update();
		
		void render();
		
	private:
		Image m_tileset;
		Map m_currentMap;
		Sprite m_character;
};

#endif // MAPSTATE_HPP_
