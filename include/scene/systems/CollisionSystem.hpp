/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.hpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 02:22:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "SceneObject.hpp"

class CollisionSystem {
	public:
		static bool inCollision(SceneObject &object1, SceneObject &object2);
};

#endif // COLLISIONSYSTEM_HPP_
