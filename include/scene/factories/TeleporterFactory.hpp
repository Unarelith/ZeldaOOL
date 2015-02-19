/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.hpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 17:50:48
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TELEPORTERFACTORY_HPP_
#define TELEPORTERFACTORY_HPP_

#include "SceneObject.hpp"
#include "Types.hpp"

class TeleporterFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // TELEPORTERFACTORY_HPP_
