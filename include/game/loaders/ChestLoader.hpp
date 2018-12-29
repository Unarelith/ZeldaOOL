/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:16:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTLOADER_HPP_
#define CHESTLOADER_HPP_

#include <gk/core/XMLFile.hpp>

#include "Scene.hpp"

class ChestLoader {
	public:
		static void load(tinyxml2::XMLElement *chestElement, Scene &scene);
};

#endif // CHESTLOADER_HPP_
