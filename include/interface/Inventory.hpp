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

#include <memory>
#include <map>

#include "Types.hpp"
#include "Vector2.hpp"

class Weapon;

class Inventory {
	public:
		template<typename WeaponType, typename... Args>
		Vector2i addWeapon(Args &&...args) {
			Vector2i position = findEmptyPosition();
			m_weapons.emplace(position, std::make_shared<WeaponType>(std::forward<Args>(args)...));
			return position;
		}
		
		Vector2i findEmptyPosition();
		
		void swapWeapons(Vector2i pos1, Vector2i pos2);
		
		Weapon *getWeaponByPosition(Vector2i position) { return m_weapons[position].get(); }
		
		Weapon *weaponA() { return getWeaponByPosition(Vector2i('A', 'A')); }
		Weapon *weaponB() { return getWeaponByPosition(Vector2i('B', 'B')); }
		
		void setWeaponA(Vector2i position) { swapWeapons(position, Vector2i('A', 'A')); }
		void setWeaponB(Vector2i position) { swapWeapons(position, Vector2i('B', 'B')); }
		
		void addRupees(u16 rupees);
		u16 rupees() const { return m_rupees; }
		
	private:
		std::map<Vector2i, std::shared_ptr<Weapon>> m_weapons;
		
		u16 m_rupees = 197;
};

#endif // INVENTORY_HPP_
