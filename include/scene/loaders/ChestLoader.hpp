/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:16:14
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
		static void load(XMLElement *chestElement, Scene &scene);
};

#endif // CHESTLOADER_HPP_
