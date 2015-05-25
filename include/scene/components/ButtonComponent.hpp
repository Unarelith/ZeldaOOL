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

#include "IntTypes.hpp"
#include "Vector2.hpp"

class TileChange {
	public:
		TileChange(Vector2u16 _tile, s16 _oldID, u16 _newID)
			: tile(_tile), oldID(_oldID), newID(_newID) {}
		
		Vector2u16 tile;
		
		s16 oldID;
		u16 newID;
};

class ButtonComponent {
	public:
		void addTileChange(Vector2u16 tile, u16 newID);
		
		void pressedAction(Vector2u16 buttonTile);
		void releasedAction(Vector2u16 buttonTile);
		
		const std::vector<TileChange> &tileChanges() const { return m_tileChanges; }
		
	private:
		bool m_pressed = true;
		
		std::vector<TileChange> m_tileChanges;
};

#endif // BUTTONCOMPONENT_HPP_
