/*
 * =====================================================================================
 *
 *       Filename:  PushingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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

