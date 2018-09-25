/*
 * =====================================================================================
 *
 *       Filename:  WeaponFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/05/2015 23:57:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LifetimeComponent.hpp"
#include "SwordFactory.hpp"
#include "WeaponComponent.hpp"
#include "WeaponFactory.hpp"

SceneObject WeaponFactory::create(Weapon &weaponInfos, float x, float y, GameKey key, SceneObject &owner) {
	if(weaponInfos.name() == "swordL1") {
		return SwordFactory::create(x, y, key, owner, weaponInfos);
	}
	else if(weaponInfos.name() == "strengthL1") {
		SceneObject object;
		object.set<LifetimeComponent>();
		object.set<WeaponComponent>(owner, weaponInfos, key, "Grab");
		return object;
	}
	else {
		return SceneObject();
	}
}

