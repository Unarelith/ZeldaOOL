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

#include "Direction.hpp"
#include "SceneObject.hpp"

class SwordFactory {
	public:
		static SceneObject create(float x, float y, Direction direction, SceneObject &owner);
};

#endif // SWORDFACTORY_HPP_
