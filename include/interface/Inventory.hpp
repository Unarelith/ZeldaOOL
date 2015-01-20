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

#include <array>
#include <memory>

#include "Types.hpp"
#include "Vector2.hpp"

class Weapon;

class Inventory {
	public:
		template<typename WeaponType, typename... Args>
		std::unique_ptr<Weapon> &addWeapon(Args &&...args) {
			Vector2i pos = findEmptyPosition();
			m_weapons[pos.x][pos.y].reset(new WeaponType(std::forward<Args>(args)...));
			return m_weapons[pos.x][pos.y];
		}
		
		Vector2i findEmptyPosition();
		
		std::unique_ptr<Weapon> &getWeapon(u8 x, u8 y) { return m_weapons[x][y]; }
		
		Weapon *weaponA() { return m_weaponA.get(); }
		Weapon *weaponB() { return m_weaponB.get(); }
		
		void setWeaponA(std::unique_ptr<Weapon> &weapon) { m_weaponA.swap(weapon); }
		void setWeaponB(std::unique_ptr<Weapon> &weapon) { m_weaponB.swap(weapon); }
		
		void addRupees(u16 rupees);
		u16 rupees() const { return m_rupees; }
		
	private:
		std::array<std::array<std::unique_ptr<Weapon>, 4>, 4> m_weapons;
		
		std::unique_ptr<Weapon> m_weaponA;
		std::unique_ptr<Weapon> m_weaponB;
		
		u16 m_rupees = 197;
};

#endif // INVENTORY_HPP_
