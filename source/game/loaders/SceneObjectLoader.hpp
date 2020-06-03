/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:15:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLOADER_HPP_
#define SCENEOBJECTLOADER_HPP_

#include <gk/scene/Scene.hpp>

class SceneObjectLoader {
	public:
		static void load(const std::string &mapName, gk::Scene &scene);
};

#endif // SCENEOBJECTLOADER_HPP_
