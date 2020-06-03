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
#ifndef COLLECTABLECOMPONENT_HPP_
#define COLLECTABLECOMPONENT_HPP_

#include <functional>
#include <string>

#include <gk/scene/SceneObject.hpp>

class CollectableComponent {
		using CollectableAction = std::function<void(gk::SceneObject&)>;

	public:
		CollectableComponent(const std::string &soundEffectName)
			: m_soundEffectName(soundEffectName) {}

		void action(gk::SceneObject &player) { if(m_action) m_action(player); }

		void setAction(CollectableAction action) { m_action = action; }

		const std::string &soundEffectName() const { return m_soundEffectName; }

	private:
		CollectableAction m_action;

		std::string m_soundEffectName;
};

#endif // COLLECTABLECOMPONENT_HPP_
