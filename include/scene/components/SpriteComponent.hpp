/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:
 *
 *        Created:  12/04/2018 16:21:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <functional>
#include <map>

#include "PositionComponent.hpp"
#include "Sprite.hpp"
#include "SceneObject.hpp"

struct SpriteState {
	SpriteState(bool _handleDirection, bool _isAnimated, u16 _animationID, u16 _frameID)
		: handleDirection(_handleDirection), isAnimated(_isAnimated), animationID(_animationID), frameID(_frameID) {}

	bool handleDirection;
	bool isAnimated;

	u16 animationID;
	u16 frameID;
};

class SpriteComponent {
	public:
		SpriteComponent(const std::string &textureName, u16 frameWidth, u16 frameHeight);

		void addState(const std::string &name, bool handleDirection, bool isAnimated, u16 animationID, u16 frameID = 0);
		void setState(const std::string &name, SceneObject &object, u16 frameOffset = 0);
		const SpriteState &getState(const std::string &name) const;
		const SpriteState &getCurrentState() const { return getState(m_currentState); }
		bool hasCurrentState() const { return m_currentState != "NULL"; }

		void updateAnimations();

		const Sprite &sprite() const { return m_sprite; }

		// FIXME: Remove this when animations will be loaded from config files
		Sprite &sprite() { return m_sprite; }

		bool isEnabled() const { return m_isEnabled; }
		void setEnabled(bool isEnabled) { m_isEnabled = isEnabled; }
		void setAnimated(bool isAnimated) { m_isAnimated = isAnimated; }

	private:
		Sprite m_sprite;

		std::string m_currentState = "NULL";

		std::map<std::string, SpriteState> m_states;

		bool m_isEnabled = true;
		bool m_isAnimated = true;
};

#endif // SPRITECOMPONENT_HPP_
