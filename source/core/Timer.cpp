/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:31:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "TimeManager.hpp"
#include "Timer.hpp"

Timer::Timer() {
	m_t = TimeManager::getTicks();
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
		m_tick = TimeManager::getTicks() - m_t;
	}
}

void Timer::start() {
	if(!m_isStarted) {
		m_isStarted = true;
		m_t = TimeManager::getTicks() - m_tick;
	}
}

void Timer::reset() {
	m_t = TimeManager::getTicks();
	m_isStarted = false;
	m_tick = 0;
}

u16 Timer::time() {
	if(m_isStarted) {
		return TimeManager::getTicks() - m_t;
	} else {
		return m_tick;
	}
}

void Timer::setTime(u16 time) {
	if(m_isStarted) {
		m_t = TimeManager::getTicks() - time;
	} else {
		m_tick = time;
	}
}

