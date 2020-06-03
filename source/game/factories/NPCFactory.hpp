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

#include <gk/scene/SceneObject.hpp>

class NPCFactory {
	public:
		static gk::SceneObject create(u16 tileX, u16 tileY);

	private:
		static void npcAction(gk::SceneObject &npc, gk::SceneObject &object, bool inCollision);
};

#endif // NPCFACTORY_HPP_
