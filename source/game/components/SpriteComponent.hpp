/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <functional>
#include <map>

#include <gk/scene/SceneObject.hpp>

#include "PositionComponent.hpp"
#include "Sprite.hpp"

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
		SpriteComponent(const std::string &resourceName);
		SpriteComponent(const std::string &textureName, u16 frameWidth, u16 frameHeight)
			: m_textureName(textureName), m_sprite(textureName, frameWidth, frameHeight) {}

		void addState(const std::string &name, bool handleDirection, bool isAnimated, u16 animationID, u16 frameID = 0);
		void setState(const std::string &name, gk::SceneObject &object, u16 frameOffset = 0);
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
		std::string m_textureName;

		Sprite m_sprite;

		std::string m_currentState = "NULL";

		std::map<std::string, SpriteState> m_states;

		bool m_isEnabled = true;
		bool m_isAnimated = true;
};

#endif // SPRITECOMPONENT_HPP_
