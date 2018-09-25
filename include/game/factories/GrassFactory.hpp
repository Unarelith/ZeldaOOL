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

#include "SceneObject.hpp"

class GrassFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY, bool lowGrass = false);
};

#endif // GRASSFACTORY_HPP_
