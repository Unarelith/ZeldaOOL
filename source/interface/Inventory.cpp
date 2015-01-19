/*
 * =====================================================================================
 *
 *       Filename:  Inventory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:31:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Inventory.hpp"

Vector2i Inventory::findEmptyPosition() {
	for(u8 i = 0 ; i < 16 ; i++) {
		Vector2i position(i % 4, i / 4);
		
		if(m_weapons.find(position) != m_weapons.end()) {
			return position;
		}
	}
	
	return Vector2i(-1, -1);
}

void Inventory::swapWeapons(Vector2i pos1, Vector2i pos2) {
	std::swap(m_weapons[pos1], m_weapons[pos2]);
}

void Inventory::addRupees(u16 rupees) {
	m_rupees += rupees;
	
	if(m_rupees > 999) m_rupees = 999;
}

