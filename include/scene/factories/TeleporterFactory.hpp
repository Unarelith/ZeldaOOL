/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.hpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 17:50:48
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERFACTORY_HPP_
#define TELEPORTERFACTORY_HPP_

#include "SceneObject.hpp"
#include "Types.hpp"

class TeleporterFactory {
	public:
		static SceneObject create(float tileX, float tileY);
};

#endif // TELEPORTERFACTORY_HPP_
