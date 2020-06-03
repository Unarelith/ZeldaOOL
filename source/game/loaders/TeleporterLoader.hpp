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

#include <gk/core/XMLFile.hpp>
#include <gk/scene/Scene.hpp>

class TeleporterLoader {
	public:
		static void load(tinyxml2::XMLElement *teleporterElement, gk::Scene &scene);
};

#endif // TELEPORTERLOADER_HPP_
