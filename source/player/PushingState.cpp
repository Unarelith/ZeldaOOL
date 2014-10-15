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
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "PushingState.hpp"

PushingState::PushingState() {
	m_name = "Pushing";
}

PushingState::~PushingState() {
}

void PushingState::update() {
	m_player.stateManager().setNextState("Moving");
	
	MovingState::update();
}

void PushingState::draw() {
	m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 4);
}

