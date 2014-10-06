/*
 * =====================================================================================
 *
 *       Filename:  Door.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2014 18:13:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DOOR_HPP_
#define DOOR_HPP_

#include "Object.hpp"

class Door : public Object {
	public:
		Door(float x, float y);
		~Door();
		
		void setDestination(u16 area, u8 mapX, u8 mapY, float playerX, float playerY, u8 playerDirection);
		
		void onEvent(u8 event);
		
	private:
		u16 m_area;
		
		u8 m_mapX;
		u8 m_mapY;
		
		u16 m_playerX;
		u16 m_playerY;
		
		u8 m_playerDirection;
};

#endif // DOOR_HPP_
