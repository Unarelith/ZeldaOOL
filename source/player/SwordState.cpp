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

s16 swordPosition[4][5][2] = {
	{{-12,   0}, {-12,  12}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{  0, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  0, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 12,   0}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -11}}
};

SwordState::SwordState() {
	m_stateType = StateType::TypeSword;
	m_nextStateType = StateType::TypeSword;
	
	m_sword.load("graphics/animations/sword.png", 16, 16);
	
	m_sword.addAnimation({0, 4, 8, 8}, 90);
	m_sword.addAnimation({1, 5, 9, 9}, 90);
	m_sword.addAnimation({2, 6, 10, 10}, 90);
	m_sword.addAnimation({3, 7, 11, 11}, 90);
}

SwordState::~SwordState() {
}

void SwordState::update() {
	if(m_player.animationAtEnd(m_player.direction() + 8)) {
		if(!Keyboard::isKeyPressed(Keyboard::A)) {
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
	if(!m_sword.animationAtEnd(m_player.direction())) {
		s16 swordX = m_player.x() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][0];
		s16 swordY = m_player.y() + swordPosition[m_player.direction()][m_sword.animationCurrentFrame(m_player.direction())][1];
		
		m_sword.playAnimation(swordX, swordY, m_player.direction());
	} else {
		s16 swordX = m_player.x() + swordPosition[m_player.direction()][4][0];
		s16 swordY = m_player.y() + swordPosition[m_player.direction()][4][1];
		
		m_sword.drawFrame(swordX, swordY, m_player.direction() + 8);
	}
}

