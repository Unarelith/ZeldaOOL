/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:24:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERFACTORY_HPP_
#define PLAYERFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class PlayerFactory {
	public:
		static gk::SceneObject create(float x, float y);
};

#endif // PLAYERFACTORY_HPP_
