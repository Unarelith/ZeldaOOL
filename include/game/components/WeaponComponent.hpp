/*
 * =====================================================================================
 *
 *       Filename:  WeaponComponent.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:58:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WEAPONCOMPONENT_HPP_
#define WEAPONCOMPONENT_HPP_

#include <gk/scene/SceneObject.hpp>

#include "InventoryComponent.hpp"

class WeaponComponent {
	public:
		WeaponComponent(gk::SceneObject &_owner, Weapon &_weaponInfos, gk::GameKey _key, const std::string &_playerState)
			: owner(_owner), weaponInfos(_weaponInfos), key(_key), playerState(_playerState) {}

		gk::SceneObject &owner;
		Weapon &weaponInfos;

		gk::GameKey key;

		std::string playerState;
};

#endif // WEAPONCOMPONENT_HPP_
