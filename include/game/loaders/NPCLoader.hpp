/*
 * =====================================================================================
 *
 *       Filename:  NPCLoader.hpp
 *
 *    Description:
 *
 *        Created:  22/06/2015 13:09:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef NPCLOADER_HPP_
#define NPCLOADER_HPP_

#include <gk/core/XMLFile.hpp>

#include "Scene.hpp"

class NPCLoader {
	public:
		static void load(tinyxml2::XMLElement *npcElement, Scene &scene);
};

#endif // NPCLOADER_HPP_
