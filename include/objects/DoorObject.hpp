/*
 * =====================================================================================
 *
 *       Filename:  DoorObject.hpp
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
#ifndef DOOROBJECT_HPP_
#define DOOROBJECT_HPP_

#include "Object.hpp"

class DoorObject : public Object {
	public:
		DoorObject(float x, float y) : Object(x, y) {}
		
		void setDestination(u16 area, u8 mapX, u8 mapY, float playerX, float playerY, u8 playerDirection);
		
		void onEvent(u8 event);
		
	private:
		u16 m_area = 0;
		
		u8 m_mapX = 0;
		u8 m_mapY = 0;
		
		u16 m_playerX = 0;
		u16 m_playerY = 0;
		
		u8 m_playerDirection = 0;
};

#endif // DOOROBJECT_HPP_
