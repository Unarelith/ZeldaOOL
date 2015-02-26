/*
 * =====================================================================================
 *
 *       Filename:  LifetimeComponent.hpp
 *
 *    Description:  
 *
 *        Created:  26/02/2015 16:40:37
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMECOMPONENT_HPP_
#define LIFETIMECOMPONENT_HPP_

#include "Timer.hpp"

class LifetimeComponent {
	public:
		LifetimeComponent(u32 lifetime) : m_lifetime(lifetime) {
			m_timer.start();
		}
		
		u32 aliveTime() { return m_timer.time(); }
		
		void kill() { m_dead = true; }
		
		bool almostDead() { return m_timer.time() > m_lifetime / 4 * 3; }
		bool dead() { return m_dead || m_timer.time() > m_lifetime; }
		
	private:
		Timer m_timer;
		
		bool m_dead = false;
		
		u32 m_lifetime = 0;
};

#endif // LIFETIMECOMPONENT_HPP_
