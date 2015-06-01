/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 00:09:00
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
		static void checkCollision(SceneObject &object1, SceneObject &object2);
		
		static bool inCollision(SceneObject &object1, SceneObject &object2);
};

#endif // COLLISIONSYSTEM_HPP_
