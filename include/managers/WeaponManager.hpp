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

#include "Weapon.hpp"

class WeaponManager {
	public:
		static void init();
		
		static Weapon *getWeaponByID(u8 id);
		
		enum WeaponID {
			SwordID
		};
		
	private:
		static std::vector<std::unique_ptr<Weapon>> weapons;
};

#endif // WEAPONMANAGER_HPP_
