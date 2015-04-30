/*
 * =====================================================================================
 *
 *       Filename:  ButtonObject.hpp
 *
 *    Description:  
 *
 *        Created:  20/01/2015 02:00:25
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTONOBJECT_HPP_
#define BUTTONOBJECT_HPP_

#include "MapObject.hpp"

class ButtonObject : public MapObject {
	public:
		ButtonObject(float x, float y) : MapObject(x, y, 16, 16) {}
		
		void addTileChange(u16 tileX, u16 tileY, u16 newTileID);
		
		void onEvent(u8 event);
		
	private:
		std::vector<std::tuple<u16, u16, u16>> m_mapChanges;
};

#endif // BUTTONOBJECT_HPP_
