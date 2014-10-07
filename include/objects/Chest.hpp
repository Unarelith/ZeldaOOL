/*
 * =====================================================================================
 *
 *       Filename:  Chest.hpp
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
#ifndef CHEST_HPP_
#define CHEST_HPP_

#include "Object.hpp"

class Chest : public Object {
	public:
		Chest(float x, float y);
		~Chest();
		
		void onEvent(u8 event);
		
		void resetTiles(Map *map);
		
	private:
		bool m_opened;
};

#endif // CHEST_HPP_
