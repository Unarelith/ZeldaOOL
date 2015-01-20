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

std::pair<int, int> Inventory::findEmptyPosition() {
	for(u8 i = 0 ; i < 16 ; i++) {
		auto position = std::make_pair(i % 4, i / 4);
		
		if(m_weapons[position.first][position.second]) {
			return position;
		}
	}
	
	return std::make_pair(-1, -1);
}

void Inventory::addRupees(u16 rupees) {
	m_rupees += rupees;
	
	if(m_rupees > 999) m_rupees = 999;
}

