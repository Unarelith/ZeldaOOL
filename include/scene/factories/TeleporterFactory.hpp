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
#include "Vector2.hpp"

class TeleporterFactory {
	public:
		static SceneObject create(Vector2f tile);
};

#endif // TELEPORTERFACTORY_HPP_
