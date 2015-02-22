/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.cpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 16:48:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Filesystem.hpp"
#include "SceneObjectLoader.hpp"
#include "TeleporterLoader.hpp"
#include "XMLFile.hpp"

void SceneObjectLoader::load(const std::string &mapName, Scene &scene) {
	if(Filesystem::fileExists("data/config/maps/" + mapName + ".xml")) {
		XMLFile doc("data/config/maps/" + mapName + ".xml");
		
		XMLElement *objectElement = doc.FirstChildElement("map").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();
			
			if(objectName == "teleporter") {
				TeleporterLoader::load(objectElement, scene);
			}
			else if(objectName == "button") {
				//ButtonLoader::load(objectElement, scene);
			}
			
			objectElement = objectElement->NextSiblingElement();
		}
	}
}

