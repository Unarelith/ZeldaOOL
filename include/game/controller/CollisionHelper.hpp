/*
 * =====================================================================================
 *
 *       Filename:  CollisionHelper.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:09:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONHELPER_HPP_
#define COLLISIONHELPER_HPP_

#include <gk/scene/CollisionHelper.hpp>

class CollisionHelper : public gk::CollisionHelper {
	public:
		bool inCollision(gk::SceneObject &object1, gk::SceneObject &object2) override;
};

#endif // COLLISIONHELPER_HPP_
