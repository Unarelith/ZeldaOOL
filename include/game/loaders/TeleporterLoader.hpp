/*
 * =====================================================================================
 *
 *       Filename:  TeleporterLoader.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 15:55:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
