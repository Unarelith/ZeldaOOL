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
		void checkCollisions(SceneObject &object);
		
		void collisionActions(SceneObject &object1, SceneObject &object2);
		
		void addChecker(std::function<void(SceneObject&)> checker) {
			m_checkers.push_back(checker);
		}
		
		void addAction(std::function<void(SceneObject&, SceneObject&)> action) {
			m_actions.push_back(action);
		}
		
	private:
		std::vector<std::function<void(SceneObject&)>> m_checkers;
		
		std::vector<std::function<void(SceneObject&, SceneObject&)>> m_actions;
};

#endif // COLLISIONCOMPONENT_HPP_
