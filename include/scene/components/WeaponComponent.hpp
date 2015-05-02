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

#include "SceneObject.hpp"

class WeaponComponent {
	public:
		WeaponComponent(SceneObject &_owner) : owner(_owner) {}
		
		SceneObject &owner;
};

#endif // WEAPONCOMPONENT_HPP_
