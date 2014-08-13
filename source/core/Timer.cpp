/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:26:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Timer.hpp"

sf::Clock Timer::systemTime;

Timer::Timer() {
	reset();
}

Timer::~Timer() {
}

void Timer::stop() {
	if(m_isStarted) {
		m_isStarted = false;
		m_tick = systemTime.getElapsedTime().asMilliseconds() - m_t;
	}
}

void Timer::start() {
	if(!m_isStarted) {
		m_isStarted = true;
		m_t = systemTime.getElapsedTime().asMilliseconds() - m_tick;
	}
}

void Timer::reset() {
	m_t = systemTime.getElapsedTime().asMilliseconds();
	m_tick = 0;
	m_isStarted = false;
}

