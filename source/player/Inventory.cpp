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
#include "WeaponManager.hpp"

Inventory::Inventory() {
	m_rupees = 197;
	
	m_weaponA = nullptr;
	m_weaponB = nullptr;
}

Inventory::~Inventory() {
}

void Inventory::addRupees(u16 rupees) {
	m_rupees += rupees;
	
	if(m_rupees > 999) {
		m_rupees = 999;
	}
}

void Inventory::addWeapon(u8 weaponID, Vector2i position) {
	if(position == Vector2i(-1, -1)) {
		for(u8 i = 0 ; i < 16 ; i++) {
			if(getWeaponByPosition(Vector2i(i % 4, i / 4)) == nullptr) {
				position = Vector2i(i % 4, i / 4);
				
				break;
			}
		}
	}
	
	m_weapons.push_back(std::make_pair(WeaponManager::weapons[weaponID], position));
}

Weapon *Inventory::getWeaponByPosition(Vector2i position) {
	for(auto &it : m_weapons) {
		if(position == it.second) {
			return it.first;
		}
	}
	
	return nullptr;
}

void Inventory::removeWeaponByPosition(Vector2i position) {
	for(u16 i = 0 ; i < m_weapons.size() ; i++) {
		if(position == m_weapons[i].second) {
			m_weapons.erase(m_weapons.begin() + i);
			
			break;
		}
	}
}

void Inventory::removeWeaponByID(u8 id) {
	for(u16 i = 0 ; i < m_weapons.size() ; i++) {
		if(id == m_weapons[i].first->id()) {
			m_weapons.erase(m_weapons.begin() + i);
			
			break;
		}
	}
}

