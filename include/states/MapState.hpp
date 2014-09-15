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

#include "GameState.hpp"
#include "Image.hpp"

class MapState : public GameState {
	public:
		MapState();
		~MapState();
		
		void update();
		
		void render();
		
	private:
		Image m_test;
};

#endif // MAPSTATE_HPP_