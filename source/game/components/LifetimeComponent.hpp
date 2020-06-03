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
#ifndef LIFETIMECOMPONENT_HPP_
#define LIFETIMECOMPONENT_HPP_

#include <functional>

#include <gk/core/Timer.hpp>
#include <gk/scene/SceneObject.hpp>

class LifetimeComponent {
	using DeathChecker = std::function<bool(const gk::SceneObject &)>;

	public:
		LifetimeComponent() = default;
		LifetimeComponent(u32 lifetime) : m_lifetime(lifetime) { m_timer.start(); }
		LifetimeComponent(DeathChecker deathChecker) : m_deathChecker(deathChecker) {}

		void kill() { m_dead = true; }

		bool almostDead() { return m_lifetime != 0 && m_timer.time() > m_lifetime / 4 * 3; }

		bool dead(const gk::SceneObject &object) {
			return m_dead
				|| (m_lifetime != 0 && m_timer.time() > m_lifetime)
				|| (m_deathChecker && m_deathChecker(object));
		}

		u32 aliveTime() { return m_timer.time(); }

		void setDeathChecker(DeathChecker deathChecker) { m_deathChecker = deathChecker; }

	private:
		gk::Timer m_timer;

		bool m_dead = false;

		u32 m_lifetime = 0;

		DeathChecker m_deathChecker;
};

#endif // LIFETIMECOMPONENT_HPP_
