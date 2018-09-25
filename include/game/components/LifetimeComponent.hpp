/*
 * =====================================================================================
 *
 *       Filename:  LifetimeComponent.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:44:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMECOMPONENT_HPP_
#define LIFETIMECOMPONENT_HPP_

#include <functional>

#include "SceneObject.hpp"
#include "Timer.hpp"

class LifetimeComponent {
	using DeathChecker = std::function<bool(const SceneObject &)>;

	public:
		LifetimeComponent() = default;
		LifetimeComponent(u32 lifetime) : m_lifetime(lifetime) { m_timer.start(); }
		LifetimeComponent(DeathChecker deathChecker) : m_deathChecker(deathChecker) {}

		void kill() { m_dead = true; }

		bool almostDead() { return m_lifetime != 0 && m_timer.time() > m_lifetime / 4 * 3; }

		bool dead(const SceneObject &object) {
			return m_dead
				|| (m_lifetime != 0 && m_timer.time() > m_lifetime)
				|| (m_deathChecker && m_deathChecker(object));
		}

		u32 aliveTime() { return m_timer.time(); }

		void setDeathChecker(DeathChecker deathChecker) { m_deathChecker = deathChecker; }

	private:
		Timer m_timer;

		bool m_dead = false;

		u32 m_lifetime = 0;

		DeathChecker m_deathChecker;
};

#endif // LIFETIMECOMPONENT_HPP_
