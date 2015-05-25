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

#include "Vector2.hpp"

#include "SceneObject.hpp"
#include "HitboxesComponent.hpp"

class CollisionInformations {
	public:
		CollisionInformations() = default;
		
		void addInformation(Hitbox hitbox1, Hitbox hitbox2) {
			m_touchingHitboxes.push_back(std::pair<Hitbox, Hitbox>(hitbox1, hitbox2));
		}
		
		std::pair<Hitbox, Hitbox> &operator[](size_t index) {
			return m_touchingHitboxes[index];
		}
		
		size_t size() const { return m_touchingHitboxes.size(); }
		
		bool empty() { return m_touchingHitboxes.empty(); }
		
		std::vector<std::pair<Hitbox, Hitbox>> m_touchingHitboxes;
};

class CollisionSystem {
	public:
		static void checkCollision(SceneObject &object1, SceneObject &object2);
		
		static void inCollision(SceneObject &object1, SceneObject &object2, CollisionInformations &collisionInformations);
};

#endif // COLLISIONSYSTEM_HPP_
