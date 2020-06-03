/*
 * =====================================================================================
 *
 *       Filename:  SwordFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:29:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORDFACTORY_HPP_
#define SWORDFACTORY_HPP_

#include <gk/core/input/InputHandler.hpp>
#include <gk/scene/SceneObject.hpp>

#include "InventoryComponent.hpp"

class SwordFactory {
	public:
		static gk::SceneObject create(float x, float y, gk::GameKey key, gk::SceneObject &owner, Weapon &weaponInfos);
};

#endif // SWORDFACTORY_HPP_
