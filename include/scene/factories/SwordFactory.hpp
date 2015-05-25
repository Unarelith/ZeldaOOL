/*
 * =====================================================================================
 *
 *       Filename:  SwordFactory.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 17:29:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORDFACTORY_HPP_
#define SWORDFACTORY_HPP_

#include "GameKey.hpp"
#include "InventoryComponent.hpp"
#include "SceneObject.hpp"
#include "Vector2.hpp"

class SwordFactory {
	public:
		static SceneObject create(Vector2f position, GameKey key, SceneObject &owner, Weapon &weaponInfos);
};

#endif // SWORDFACTORY_HPP_
