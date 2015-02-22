/*
 * =====================================================================================
 *
 *       Filename:  CollisionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  18/02/2015 15:04:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <vector>

#include "SceneObject.hpp"

using CollisionChecker = std::function<void(SceneObject&)>;
using CollisionAction  = std::function<void(SceneObject&, SceneObject&, bool)>;

class CollisionComponent {
	public:
		void checkCollisions(SceneObject &object);
		
		void collisionActions(SceneObject &object1, SceneObject &object2, bool collision);
		
		void addChecker(CollisionChecker checker) {
			m_checkers.push_back(checker);
		}
		
		void addAction(CollisionAction action) {
			m_actions.push_back(action);
		}
		
	private:
		std::vector<CollisionChecker> m_checkers;
		
		std::vector<CollisionAction> m_actions;
};

#endif // COLLISIONCOMPONENT_HPP_
