/*
 * =====================================================================================
 *
 *       Filename:  WeaponComponent.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 17:58:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WEAPONCOMPONENT_HPP_
#define WEAPONCOMPONENT_HPP_

#include "GameKey.hpp"
#include "InventoryComponent.hpp"
#include "SceneObject.hpp"

class WeaponComponent {
	public:
		WeaponComponent(SceneObject &_owner, Weapon &_weaponInfos, GameKey _key, const std::string &_playerState)
			: owner(_owner), weaponInfos(_weaponInfos), key(_key), playerState(_playerState) {}
		
		SceneObject &owner;
		Weapon &weaponInfos;
		
		GameKey key;
		
		std::string playerState;
};

#endif // WEAPONCOMPONENT_HPP_
