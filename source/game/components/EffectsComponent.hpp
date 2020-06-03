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
#ifndef EFFECTSCOMPONENT_HPP_
#define EFFECTSCOMPONENT_HPP_

#include <map>
#include <string>

#include "Sprite.hpp"

class Effect : public Sprite {
	public:
		Effect(const std::string &textureName, u16 frameWidth, u16 frameHeight, gk::Vector2f _offset = {0, 0})
			: Sprite(textureName, frameWidth, frameHeight), offset(_offset) {}

		gk::Vector2i offset;
		bool isEnabled = false;
};

class EffectsComponent {
	public:
		Effect &addEffect(const std::string &name, const std::string &textureName, u16 frameWidth, u16 frameHeight, gk::Vector2f offset = {0, 0}) {
			m_effects.emplace(name, Effect{textureName, frameWidth, frameHeight, offset});
			return m_effects.at(name);
		}

		void enableIf(const std::string &name, bool condition) {
			m_effects.at(name).isEnabled = condition;
		}

		void enable(const std::string &name) {
			m_effects.at(name).isEnabled = true;
		}

		std::map<std::string, Effect> &effects() { return m_effects; }

	private:
		std::map<std::string, Effect> m_effects;
};

#endif // EFFECTSCOMPONENT_HPP_
