/*
 * =====================================================================================
 *
 *       Filename:  GrassFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 20:32:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GRASSFACTORY_HPP_
#define GRASSFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class GrassFactory {
	public:
		static gk::SceneObject create(u16 tileX, u16 tileY, bool lowGrass = false);

	private:
		static void grassAction(gk::SceneObject &grass, gk::SceneObject &object, bool inCollision);
};

#endif // GRASSFACTORY_HPP_
