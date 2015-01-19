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
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "Types.hpp"

class Timer {
	public:
		Timer(bool useRealTime = false);
		Timer(const Timer &) = default;
		Timer(Timer &&) = default;
		
		void stop();
		void start();
		void reset();
		
		u32 time();
		
		void setTime(u32 time);
		
		bool isStarted() const { return m_isStarted; }
		
	private:
		bool m_useRealTime = false;
		
		bool m_isStarted = false;
		
		u32 m_t = 0;
		u32 m_tick = 0;
};

#endif // TIMER_HPP_
