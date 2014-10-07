/*
 * =====================================================================================
 *
 *       Filename:  ChestObject.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2014 20:24:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHESTOBJECT_HPP_
#define CHESTOBJECT_HPP_

#include "Collectable.hpp"
#include "Object.hpp"

class ChestObject : public Object {
	public:
		ChestObject(float x, float y);
		~ChestObject();
		
		void onEvent(u8 event);
		
		void resetTiles(Map *map);
		
	private:
		bool m_opened;
		
		Collectable *m_collectable;
};

#endif // CHESTOBJECT_HPP_
