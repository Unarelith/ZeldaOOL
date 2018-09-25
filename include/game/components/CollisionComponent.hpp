/*
 * =====================================================================================
 *
 *       Filename:  CollisionComponent.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:29:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <functional>
#include <vector>

#include "SceneObject.hpp"

class CollisionComponent {
	using CollisionChecker = std::function<void(SceneObject&)>;
	using CollisionAction  = std::function<void(SceneObject&, SceneObject&, bool)>;

	public:
		void checkCollisions(SceneObject &object) {
			for(auto &it : m_checkers) {
				it(object);
			}
		}

		void collisionActions(SceneObject &object1, SceneObject &object2, bool inCollision) {
			for(auto &it : m_actions) {
				it(object1, object2, inCollision);
			}
		}

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
