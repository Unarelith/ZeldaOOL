/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.hpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 17:50:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERFACTORY_HPP_
#define TELEPORTERFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class TeleporterFactory {
	public:
		static gk::SceneObject create(float tileX, float tileY);

	private:
		static void teleporterAction(gk::SceneObject &teleporter, gk::SceneObject &object, bool inCollision);
};

#endif // TELEPORTERFACTORY_HPP_
