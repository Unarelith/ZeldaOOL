/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 17:11:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameClock.hpp"
#include "Timer.hpp"

Timer::Timer(bool useRealTime) {
	m_useRealTime = useRealTime;
	m_t = GameClock::getTicks(m_useRealTime);
	m_isStarted = false;
	m_tick = 0;
}

Timer::~Timer() {
	reset();
	stop();
}

void Timer::stop() {
	if(m_isStarted) {
		m_isStarted = false;
		m_tick = GameClock::getTicks(m_useRealTime) - m_t;
	}
}

void Timer::start() {
	if(!m_isStarted) {
		m_isStarted = true;
		m_t = GameClock::getTicks(m_useRealTime) - m_tick;
	}
}

void Timer::reset() {
	m_t = GameClock::getTicks(m_useRealTime);
	m_isStarted = false;
	m_tick = 0;
}

u32 Timer::time() {
	if(m_isStarted) {
		return GameClock::getTicks(m_useRealTime) - m_t;
	} else {
		return m_tick;
	}
}

void Timer::setTime(u32 time) {
	if(m_isStarted) {
		m_t = GameClock::getTicks(m_useRealTime) - time;
	} else {
		m_tick = time;
	}
}

