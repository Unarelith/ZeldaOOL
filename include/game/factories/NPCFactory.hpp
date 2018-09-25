/*
 * =====================================================================================
 *
 *       Filename:  NPCFactory.hpp
 *
 *    Description:
 *
 *        Created:  22/06/2015 12:52:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef NPCFACTORY_HPP_
#define NPCFACTORY_HPP_

#include "SceneObject.hpp"

class NPCFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // NPCFACTORY_HPP_
