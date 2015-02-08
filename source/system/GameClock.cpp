#include "GameClock.hpp"
#include "SDLHeaders.hpp"

u32 GameClock::ticks = 0;

u32 GameClock::getTicks(bool realTime) {
	if(realTime) {
		return SDL_GetTicks();
	} else {
		return ticks;
	}
}

void GameClock::measureLastFrameDuration() {
	u32 now = getTicks(true) - m_timeDropped;
	u32 lastFrameDuration = now - m_lastFrameDate;
	
	m_lastFrameDate = now;
	m_lag += lastFrameDuration;
	
	if(m_lag >= 200) {
		m_timeDropped += m_lag - timestep;
		m_lag = timestep;
		m_lastFrameDate = getTicks(true) - m_timeDropped;
	}
}

void GameClock::updateGame(std::function<void(void)> updateFunc) {
	m_numUpdates = 0;
	
	while(m_lag >= timestep && m_numUpdates < 10) {
		ticks += timestep;
		
		updateFunc();
		
		m_lag -= timestep;
		m_numUpdates++;
	}
}

void GameClock::drawGame(std::function<void(void)> drawFunc) {
	if(m_numUpdates > 0) {
		drawFunc();
	}
	
	u32 lastFrameDuration = getTicks(true) - m_timeDropped - m_lastFrameDate;
	
	if(lastFrameDuration < timestep) {
		SDL_Delay(timestep - lastFrameDuration);
	}
	
	measureLastFrameDuration();
}

