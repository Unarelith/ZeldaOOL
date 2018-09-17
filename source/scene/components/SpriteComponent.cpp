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
#include "SpriteComponent.hpp"

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

