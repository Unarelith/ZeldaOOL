/*
 * =====================================================================================
 *
 *       Filename:  Timer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:24:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <SFML/System.hpp>

#include "Types.hpp"

class Timer {
	public:
		Timer();
		~Timer();
		
		u32 time() { return (m_isStarted) ? systemTime.getElapsedTime().asMilliseconds() - m_t : m_tick; }
		
		void stop();
		void start();
		void reset();
		
		static sf::Clock systemTime;
		
	private:
		u32 m_t;
		u32 m_tick;
		bool m_isStarted;
};

#endif // TIMER_HPP_
