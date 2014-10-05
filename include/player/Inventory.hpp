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

// Player needs Inventory
// Inventory needs Weapon
// Weapon needs Player
class Weapon;

#include "Debug.hpp"

class Inventory {
	public:
		Inventory();
		~Inventory();
		
		void addWeapon(u8 weaponID, Vector2i position = Vector2i(-1, -1));
		
		Weapon *getWeaponByPosition(Vector2i position);
		
		void removeWeaponByPosition(Vector2i position);
		void removeWeaponByID(u8 id);
		
		Weapon *weaponA() const { return m_weaponA; }
		Weapon *weaponB() const { return m_weaponB; }
		
		void setWeaponA(Weapon *weapon) { m_weaponA = weapon; }
		void setWeaponB(Weapon *weapon) { m_weaponB = weapon; }
		
	private:
		std::vector<std::pair<Weapon *, Vector2i>> m_weapons;
		
		Weapon *m_weaponA;
		Weapon *m_weaponB;
};

#endif // INVENTORY_HPP_
