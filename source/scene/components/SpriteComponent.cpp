/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2018 20:14:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Filesystem.hpp"
#include "SpriteComponent.hpp"
#include "XMLFile.hpp"

SpriteComponent::SpriteComponent(const std::string &textureName, u16 frameWidth, u16 frameHeight)
: m_sprite(textureName, frameWidth, frameHeight)
{
	if (Filesystem::fileExists("resources/config/sprites/" + textureName + ".xml")) {
		XMLFile doc("resources/config/sprites/" + textureName + ".xml");

		tinyxml2::XMLElement *spriteElement = doc.FirstChildElement("sprite").ToElement();
		std::string name = spriteElement->Attribute("name");
		std::string texture = spriteElement->Attribute("texture");
		u16 frameWidth = spriteElement->IntAttribute("width");
		u16 frameHeight = spriteElement->IntAttribute("height");

		// FIXME: Load sprite here from texture and frameWidth/Height

		tinyxml2::XMLElement *stateElement = spriteElement->FirstChildElement("states")->FirstChildElement("state");
		while (stateElement) {
			std::string name = stateElement->Attribute("name");
			bool handleDirection = stateElement->BoolAttribute("directional");
			bool isAnimated = stateElement->BoolAttribute("animated");
			u16 animID = stateElement->UnsignedAttribute("anim");
			u16 frameID = stateElement->UnsignedAttribute("frame");

			addState(name, handleDirection, isAnimated, animID, frameID);

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

			m_sprite.addAnimation(animation);

			animationElement = animationElement->NextSiblingElement("animation");
		}
	}
}

void SpriteComponent::addState(const std::string &name, bool handleDirection, bool isAnimated, u16 animationID, u16 frameID) {
	m_states.emplace(name, SpriteState{handleDirection, isAnimated, animationID, frameID});
}

void SpriteComponent::setState(const std::string &name, SceneObject &object, u16 frameOffset) {
	auto it = m_states.find(name);
	if (it == m_states.end())
		throw EXCEPTION("Unable to set current state to an unexistant state:", name, "|", object.name());

	if (it->second.handleDirection) {
		m_sprite.setCurrentAnimation(it->second.animationID + static_cast<u8>(object.get<PositionComponent>().direction));
	}
	else {
		m_sprite.setCurrentAnimation(it->second.animationID);
	}

	m_sprite.setCurrentFrame(m_sprite.currentAnimation().getFrame(it->second.frameID + frameOffset));
	m_sprite.setAnimated(m_isAnimated && it->second.isAnimated);

	m_currentState = name;
}

const SpriteState &SpriteComponent::getState(const std::string &name) const {
	auto it = m_states.find(name);
	if (it == m_states.end())
		throw EXCEPTION("SpriteState not found:", name);
	return it->second;
}

void SpriteComponent::updateAnimations() {
	m_sprite.updateAnimations();
}

