/*
 * =====================================================================================
 *
 *       Filename:  WeaponFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/05/2015 23:57:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "SwordFactory.hpp"
#include "WeaponFactory.hpp"

SceneObject WeaponFactory::create(Weapon &weaponInfos, float x, float y, GameKey key, SceneObject &owner) {
	if(weaponInfos.name() == "swordL1") {
		return SwordFactory::create(x, y, key, owner, weaponInfos);
	} else {
		return SceneObject();
	}
}

