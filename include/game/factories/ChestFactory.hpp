/*
 * =====================================================================================
 *
 *       Filename:  ChestFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:12:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTFACTORY_HPP_
#define CHESTFACTORY_HPP_

#include <gk/core/IntTypes.hpp>

#include "SceneObject.hpp"

class ChestFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // CHESTFACTORY_HPP_
