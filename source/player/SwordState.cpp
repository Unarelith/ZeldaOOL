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

s16 swordPosition[4][7][2] = {
	{{-12,   0}, {-12,  12}, {-12,  12}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{  0, -12}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  0, -12}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 12,   0}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
};

SwordState::SwordState() {
	m_stateType = StateType::TypeSword;
	m_nextStateType = StateType::TypeSword;
	
	m_sword.load("graphics/animations/sword.png", 16, 16);
	
	m_sword.addAnimation({0, 4, 4, 8, 8, 8}, 40);
	m_sword.addAnimation({1, 5, 5, 9, 9, 9}, 40);
	m_sword.addAnimation({2, 6, 6, 10, 10, 10}, 40);
	m_sword.addAnimation({3, 7, 7, 11, 11, 11}, 40);
	
	m_spinAttack = false;
	
	m_tmpDirection = 0;
	
	Sound::Effect::swordSlash1.play();
}

SwordState::~SwordState() {
}

void SwordState::update() {
	if(!m_spinAttack) {
		if(m_player.animationAtEnd(m_player.direction() + 8)) {
			m_timer.start();
			
			if(!Keyboard::isKeyPressed(Keyboard::A)) {
				if(m_timer.time() > 1000) {
					Sound::Effect::swordSpin.play();
					
					m_spinAttack = true;
					
					m_tmpDirection = m_player.direction();
				} else {
					m_nextStateType = StateType::TypeStanding;
				}
			}
			else if(m_timer.time() > 1000) {
				Sound::Effect::swordCharge.play();
			}
		}
	} else {
		if(m_sword.animationAtEnd(m_player.direction())) {
			m_player.setDirection((((m_player.direction() + 1) % 4) * 4) >> 2);
		}
		
		// TmpDirection is the player's direction in the first launch of the loop
		if(m_player.direction() == m_tmpDirection) {
			m_nextStateType = StateType::TypeStanding;
		}
	}
}

void SwordState::draw() {
	if(m_player.direction() != Character::Direction::Up) {
		drawPlayer();
		
		drawSword();
	} else {
		drawSword();
		
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

void SwordState::drawSword() {
	if(!m_spinAttack) {
		if(m_timer.time() > 1000 && m_timer.time() % 200 > 100) {
			m_sword.setColor(sf::Color(50, 50, 50));
		} else {
			m_sword.setColor(sf::Color(255, 255, 255));
		}
		
		if(!m_sword.animationAtEnd(m_player.direction())) {
			s16 swordX = m_player.x() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][0];
			s16 swordY = m_player.y() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][1];
			
			m_sword.playAnimation(swordX, swordY, m_player.direction());
		} else {
			s16 swordX = m_player.x() + swordPosition[m_player.direction()][6][0];
			s16 swordY = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			m_sword.drawFrame(swordX, swordY, m_player.direction() + 8);
		}
	} else {
		s16 swordX = m_player.x() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][0];
		s16 swordY = m_player.y() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][1];
		
		m_sword.playAnimation(swordX, swordY, m_player.direction());
	}
}

