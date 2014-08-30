/*
 * =====================================================================================
 *
 *       Filename:  SwordState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 16:15:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "EffectManager.hpp"
#include "SwordState.hpp"

SwordState::SwordState() {
	m_stateType = StateType::TypeSword;
	m_nextStateType = StateType::TypeSword;
}

SwordState::~SwordState() {
}

void SwordState::update() {
	if(m_player.animationAtEnd(m_player.direction() + 8)
	&& !Keyboard::isKeyPressed(Keyboard::B)) {
		m_nextStateType = StateType::TypeStanding;
	}
}

void SwordState::draw() {
	m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 8);
	
	EffectManager::drawEffects(&m_player);
}

