/*
 * =====================================================================================
 *
 *       Filename:  ChestFactory.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 01:29:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTFACTORY_HPP_
#define CHESTFACTORY_HPP_

#include "SceneObject.hpp"
#include "Types.hpp"

class ChestFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // CHESTFACTORY_HPP_
