/*
 * =====================================================================================
 *
 *       Filename:  HealthComponent.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2015 12:22:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "IntTypes.hpp"

class HealthComponent {
	public:
		HealthComponent(u8 _maxLife, u8 _life = 0)
			: maxLife(_maxLife), life(_life ? _life : _maxLife) {}

		u8 maxLife = 0;
		u8 life = 0;

		bool isHurt = false;
		bool isDead = false;
};

#endif // HEALTHCOMPONENT_HPP_
