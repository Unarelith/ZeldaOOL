/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 01:50:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTLOADER_HPP_
#define CHESTLOADER_HPP_

#include "Scene.hpp"
#include "XMLFile.hpp"

class ChestLoader {
	public:
		static void load(XMLElement *teleporterElement, Scene &scene);
};

#endif // CHESTLOADER_HPP_
