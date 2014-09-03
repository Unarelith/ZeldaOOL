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
#include "Sound.hpp"
#include "EffectManager.hpp"
#include "SwordState.hpp"

SwordState::SwordState() {
	m_stateType = StateType::TypeSword;
	m_nextStateType = StateType::TypeSword;
	
	Sound::Effect::swordSlash1.play();
}

SwordState::~SwordState() {
}

void SwordState::update() {
	m_sword.update();
	
	if(m_sword.state() == Sword::State::Loading) {
		move();
	}
}

void SwordState::draw() {
	if(m_player.direction() != Character::Direction::Up) {
		drawPlayer();
		
		m_sword.draw();
	} else {
		m_sword.draw();
		
		drawPlayer();
	}
}

void SwordState::drawPlayer() {
	if(!m_sword.animationAtEnd(m_player.direction())) {
		m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 8);
	} else {
		m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
	}
	
	EffectManager::drawEffects(&m_player);
}

