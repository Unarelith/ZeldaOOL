/*
 * =====================================================================================
 *
 *       Filename:  NPCLoader.hpp
 *
 *    Description:
 *
 *        Created:  22/06/2015 13:09:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef NPCLOADER_HPP_
#define NPCLOADER_HPP_

#include "SceneObjectList.hpp"
#include "XMLFile.hpp"

class NPCLoader {
	public:
		static void load(XMLElement *npcElement, SceneObjectList &objectList);
};

#endif // NPCLOADER_HPP_
