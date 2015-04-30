/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.cpp
 *
 *    Description:  
 *
 *        Created:  14/01/2015 20:29:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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

