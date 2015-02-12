/*
 * =====================================================================================
 *
 *       Filename:  MapTestState.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:12:00
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPTESTSTATE_HPP_
#define MAPTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "TileMap.hpp"

class MapTestState : public ApplicationState {
	public:
		MapTestState() : m_tilemap(TileMap::getMap(0, 0, 0)) {}
		
		void update() override;
		
		void draw() override;
		
	private:
		TileMap &m_tilemap;
};

#endif // MAPTESTSTATE_HPP_
