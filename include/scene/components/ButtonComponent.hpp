/*
 * =====================================================================================
 *
 *       Filename:  ButtonComponent.hpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 03:10:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTONCOMPONENT_HPP_
#define BUTTONCOMPONENT_HPP_

#include <tuple>
#include <vector>

#include "Types.hpp"

class TileChange {
	public:
		TileChange(u16 _tileX, u16 _tileY, s16 _oldID, s16 _newID)
			: tileX(_tileX), tileY(_tileY), oldID(_oldID), newID(_newID) {}
		
		u16 tileX;
		u16 tileY;
		
		s16 oldID;
		u16 newID;
};

class ButtonComponent {
	public:
		void addTileChange(u16 tileX, u16 tileY, u16 newID);
		
		void pressedAction(u16 buttonTileX, u16 buttonTileY);
		void releasedAction(u16 buttonTileX, u16 buttonTileY);
		
		const std::vector<TileChange> &tileChanges() const { return m_tileChanges; }
		
	private:
		bool m_pressed = true;
		
		std::vector<TileChange> m_tileChanges;
};

#endif // BUTTONCOMPONENT_HPP_
