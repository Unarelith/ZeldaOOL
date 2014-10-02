/*
 * =====================================================================================
 *
 *       Filename:  WeaponManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:45:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef WEAPONMANAGER_HPP_
#define WEAPONMANAGER_HPP_

#include <vector>

#include "Weapon.hpp"

namespace WeaponManager {
	void init();
	void free();
	
	Weapon *getWeaponByID(u8 id);
	
	enum WeaponID {
		SwordID
	};
	
	extern std::vector<Weapon*> weapons;
}

#endif // WEAPONMANAGER_HPP_
