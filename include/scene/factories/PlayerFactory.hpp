/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:24:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERFACTORY_HPP_
#define PLAYERFACTORY_HPP_

#include "SceneObject.hpp"

class PlayerFactory {
	public:
		static SceneObject create(float x, float y);

		static void mapCollisions(SceneObject &player);
};

#endif // PLAYERFACTORY_HPP_
