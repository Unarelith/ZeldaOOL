/*
 * =====================================================================================
 *
 *       Filename:  SpriteLoader.cpp
 *
 *    Description:
 *
 *        Created:  19/09/2018 20:27:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Filesystem.hpp"
#include "SpriteComponent.hpp"
#include "SpriteLoader.hpp"

void SpriteLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *spriteElement = doc.FirstChildElement("sprites").FirstChildElement("sprite").ToElement();
	while(spriteElement) {
		std::string name = spriteElement->Attribute("name");
		std::string filename = "resources/config/sprites/" + name + ".xml";

		loadSprite(name, handler);

		spriteElement = spriteElement->NextSiblingElement("sprite");
	}
}

void SpriteLoader::loadSprite(const std::string &textureName, gk::ResourceHandler &handler) {
	if (Filesystem::fileExists("resources/config/sprites/" + textureName + ".xml")) {
		gk::XMLFile doc("resources/config/sprites/" + textureName + ".xml");

		tinyxml2::XMLElement *spriteElement = doc.FirstChildElement("sprite").ToElement();
		std::string name = spriteElement->Attribute("name");
		std::string texture = spriteElement->Attribute("texture");
		u16 frameWidth = spriteElement->IntAttribute("width");
		u16 frameHeight = spriteElement->IntAttribute("height");

		SpriteComponent &sprite = handler.add<SpriteComponent>("sprite-" + textureName, texture, frameWidth, frameHeight);

		tinyxml2::XMLElement *stateElement = spriteElement->FirstChildElement("states")->FirstChildElement("state");
		while (stateElement) {
			std::string name = stateElement->Attribute("name");
			bool handleDirection = stateElement->BoolAttribute("directional");
			bool isAnimated = stateElement->BoolAttribute("animated");
			u16 animID = stateElement->UnsignedAttribute("anim");
			u16 frameID = stateElement->UnsignedAttribute("frame");

			sprite.addState(name, handleDirection, isAnimated, animID, frameID);

			stateElement = stateElement->NextSiblingElement("state");
		}

		tinyxml2::XMLElement *animationElement = spriteElement->FirstChildElement("animations")->FirstChildElement("animation");
		while (animationElement) {
			u32 delay = animationElement->IntAttribute("delay");
			bool isLoop = animationElement->IntAttribute("loop");

			SpriteAnimation animation(delay, isLoop);

			tinyxml2::XMLElement *frameElement = animationElement->FirstChildElement("frame");
			while (frameElement) {
				u8 frameId = frameElement->IntAttribute("id");

				int x = frameElement->IntAttribute("x");
				int y = frameElement->IntAttribute("y");

				animation.addFrame(frameId, {x, y});

				frameElement = frameElement->NextSiblingElement("frame");
			}

			sprite.sprite().addAnimation(animation);

			animationElement = animationElement->NextSiblingElement("animation");
		}
	}
}

