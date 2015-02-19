/*
 * =====================================================================================
 *
 *       Filename:  CollisionComponent.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 02:16:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"

void CollisionComponent::checkCollisions(SceneObject &object) {
	for(auto &it : m_checkers) {
		it(object);
	}
}

void CollisionComponent::collisionActions(SceneObject &object1, SceneObject &object2) {
	for(auto &it : m_actions) {
		it(object1, object2);
	}
}

