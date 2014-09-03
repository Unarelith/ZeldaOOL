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
	
	m_sword.load("graphics/animations/sword.png", 16, 16);
	
	m_sword.addAnimation({0, 4, 4, 8, 8, 8}, 40);
	m_sword.addAnimation({1, 5, 5, 9, 9, 9}, 40);
	m_sword.addAnimation({2, 6, 6, 10, 10, 10}, 40);
	m_sword.addAnimation({3, 7, 7, 11, 11, 11}, 40);
	
	m_loading = false;
	m_spinAttack = false;
	
	m_tmpDirection = 0;
	
	Sound::Effect::swordSlash1.play();
}

SwordState::~SwordState() {
}

void SwordState::update() {
	m_sword.update();
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

