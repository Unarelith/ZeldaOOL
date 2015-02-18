/*
 * =====================================================================================
 *
 *       Filename:  CollisionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  18/02/2015 15:04:03
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <vector>

#include "SceneObject.hpp"

class CollisionComponent {
	public:
		void checkCollisions(SceneObject &object) {
			for(auto &it : checkers) it(object);
		}
		
		std::vector<std::function<void(SceneObject&)>> checkers;
		
		std::vector<std::function<void(SceneObject&, SceneObject&)>> actions;
};

#endif // COLLISIONCOMPONENT_HPP_
