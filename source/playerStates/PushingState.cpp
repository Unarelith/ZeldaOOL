/*
 * =====================================================================================
 *
 *       Filename:  PushingState.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:25:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "PushingState.hpp"

void PushingState::update() {
	if(!m_character.blocked()) {
		setNextState<MovingState>();
	}
	
	MovingState::update();
}

void PushingState::render() {
	m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction() + 4);
}

