/*
 * =====================================================================================
 *
 *       Filename:  Inventory.cpp
 *
 *    Description:  
 *
 *        Created:  02/10/2014 18:31:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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

