/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 21:08:34
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

#include "GameState.hpp"
#include "Image.hpp"
#include "Map.hpp"

class MapState : public GameState {
	public:
		MapState();
		~MapState();
		
		void update();
		
		void render();
		
	private:
		Image m_stats;
		Texture m_tileset;
		Map m_map;
};

#endif // MAPSTATE_HPP_
