/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 01:15:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLOADER_HPP_
#define SCENEOBJECTLOADER_HPP_

#include "Scene.hpp"

class SceneObjectLoader {
	public:
		static void load(const std::string &mapName, Scene &scene);
};

#endif // SCENEOBJECTLOADER_HPP_
