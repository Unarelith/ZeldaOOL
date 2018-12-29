/*
 * =====================================================================================
 *
 *       Filename:  WeaponFactory.hpp
 *
 *    Description:
 *
 *        Created:  19/05/2015 23:53:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WEAPONFACTORY_HPP_
#define WEAPONFACTORY_HPP_

#include <gk/core/input/InputHandler.hpp>

#include "InventoryComponent.hpp"
#include "SceneObject.hpp"

class WeaponFactory {
	public:
		static SceneObject create(Weapon &weaponInfos, float x, float y, gk::GameKey key, SceneObject &owner);
};

#endif // WEAPONFACTORY_HPP_
