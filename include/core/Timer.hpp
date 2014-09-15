/*
 * =====================================================================================
 *
 *       Filename:  Timer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:31:28
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

#include "Types.hpp"

class Timer {
	public:
		Timer();
		~Timer();
		
		void stop();
		void start();
		void reset();
		
		u16 time();
		
		bool isStarted() const { return m_isStarted; }
		
	private:
		u16 m_t;
		
		bool m_isStarted;
		
		u16 m_tick;
};

#endif // TIMER_HPP_
