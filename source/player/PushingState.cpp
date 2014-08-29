/*
 * =====================================================================================
 *
 *       Filename:  PushingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 05:48:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "EffectManager.hpp"
#include "PushingState.hpp"

PushingState::PushingState() {
	m_stateType = StateType::TypePushing;
	m_nextStateType = StateType::TypePushing;
}

PushingState::~PushingState() {
}

void PushingState::update() {
	m_nextStateType = StateType::TypeMoving;
	
	MovingState::update();
}

void PushingState::draw() {
	m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 4);
	
	EffectManager::drawEffects(&m_player);
}

