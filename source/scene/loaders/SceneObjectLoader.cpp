/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 01:15:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Filesystem.hpp"
#include "SceneObjectLoader.hpp"
#include "XMLFile.hpp"

#include "ChestLoader.hpp"
#include "OctorokLoader.hpp"

void SceneObjectLoader::load(const std::string &mapName, Scene &scene) {
	if(Filesystem::fileExists("data/config/maps/" + mapName + ".xml")) {
		XMLFile doc("data/config/maps/" + mapName + ".xml");
		
		XMLElement *objectElement = doc.FirstChildElement("map").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();
			
			if(objectName == "chest") {
				ChestLoader::load(objectElement, scene);
			}
			else if(objectName == "octorok") {
				OctorokLoader::load(objectElement, scene);
			}
			
			objectElement = objectElement->NextSiblingElement();
		}
	}
}

