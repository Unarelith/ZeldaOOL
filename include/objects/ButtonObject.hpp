/*
 * =====================================================================================
 *
 *       Filename:  ButtonObject.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/01/2015 02:00:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BUTTONOBJECT_HPP_
#define BUTTONOBJECT_HPP_

#include "Object.hpp"

class ButtonObject : public Object {
	public:
		ButtonObject(float x, float y) : Object(x, y) {}
		
		void addTileChange(u16 tileX, u16 tileY, u16 newTileID);
		
		void onEvent(u8 event);
		
	private:
		std::vector<std::tuple<u16, u16, u16>> m_mapChanges;
};

#endif // BUTTONOBJECT_HPP_
