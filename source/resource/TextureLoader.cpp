/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/01/2015 20:29:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "XMLFile.hpp"

void TextureLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *textureElement = doc.FirstChildElement("textures").FirstChildElement("texture").ToElement();
	while(textureElement) {
		std::string folder = textureElement->Attribute("folder");
		std::string name = textureElement->Attribute("name");
		
		std::string filename = "graphics/" + folder + "/" + name + ".png";
		
		handler.add<Texture>(folder + "-" + name, filename);
		
		textureElement = textureElement->NextSiblingElement("texture");
	}
}

