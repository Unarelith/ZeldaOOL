/*
 * =====================================================================================
 *
 *       Filename:  CollisionHelper.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:09:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONHELPER_HPP_
#define COLLISIONHELPER_HPP_

#include "SceneObject.hpp"

class CollisionHelper {
	public:
		static void checkCollision(SceneObject &object1, SceneObject &object2);

		static bool inCollision(SceneObject &object1, SceneObject &object2);
};

#endif // COLLISIONHELPER_HPP_
