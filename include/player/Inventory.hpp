/*
 * =====================================================================================
 *
 *       Filename:  Inventory.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:31:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <vector>

#include "Types.hpp"
#include "Vector2.hpp"

class Inventory {
	public:
		Inventory();
		~Inventory();
		
		void addWeapon(u8 weaponID, Vector2i position = Vector2i(-1, -1));
		
	private:
		std::vector<std::pair<u8, Vector2i>> m_weapons;
};

#endif // INVENTORY_HPP_
