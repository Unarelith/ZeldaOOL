/*
 * =====================================================================================
 *
 *       Filename:  TeleporterLoader.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 15:55:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERLOADER_HPP_
#define TELEPORTERLOADER_HPP_

#include "Scene.hpp"
#include "XMLFile.hpp"

class TeleporterLoader {
	public:
		static void load(XMLElement *teleporterElement, Scene &scene);
};

#endif // TELEPORTERLOADER_HPP_
