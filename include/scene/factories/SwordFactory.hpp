/*
 * =====================================================================================
 *
 *       Filename:  SwordFactory.hpp
 *
 *    Description:  
 *
 *        Created:  19/03/2015 22:31:53
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORDFACTORY_HPP_
#define SWORDFACTORY_HPP_

#include "SceneObject.hpp"

class SwordFactory {
	public:
		static SceneObject create(float x, float y);
};

#endif // SWORDFACTORY_HPP_
