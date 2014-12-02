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

#include "GameState.hpp"
#include "Image.hpp"

class MapState : public GameState {
	public:
		MapState();
		~MapState();
		
		void update();
		
		void draw();
		
	private:
		Image m_image;
};

#endif // MAPSTATE_HPP_
