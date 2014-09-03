/*
 * =====================================================================================
 *
 *       Filename:  Sword.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2014 19:53:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Sound.hpp"
#include "Sword.hpp"

s16 swordPosition[4][7][2] = {
	{{-12,   0}, {-12,  12}, {-12,  12}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{  0, -12}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  0, -12}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 12,   0}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
};

Sword::Sword() {
	m_state = State::Swinging;
}

Sword::~Sword() {
}

void Sword::update() {
	if(!m_state == State::SpinAttack) {
		if(m_player.animationAtEnd(m_player.direction() + 8)) {
			m_loadingTimer.start();
			
			if(!Keyboard::isKeyPressed(Keyboard::A)) {
				if(m_loadingTimer.time() > 1000) {
					Sound::Effect::swordSpin.play();
					
					m_state = State::Loading;
					
					m_tmpDirection = m_player.direction();
					
					m_player.turn();
					
					m_sword.setColor(sf::Color(255, 255, 255));
				} else {
					m_nextStateType = StateType::TypeStanding;
				}
			}
			else if(m_loadingTimer.time() > 1000 && !m_loading) {
				m_state = State::Loading;
				
				Sound::Effect::swordCharge.play();
			}
		}
	} else {
		if(m_sword.animationAtEnd(m_player.direction())) {
			m_player.turn();
		}
		
		// TmpDirection is the player's direction at the beginning of the spin attack
		if(m_player.direction() == m_tmpDirection) {
			m_nextStateType = StateType::TypeStanding;
		}
	}
}

void Sword::draw() {
	if(!m_state == State::SpinAttack) {
		if(m_state == State::Loading && m_timer.time() % 200 > 100) {
			setColor(sf::Color(0, 0, 0));
		} else {
			setColor(sf::Color(255, 255, 255));
		}
		
		if(!animationAtEnd(m_player.direction())) {
			s16 swordX = m_player.x() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][0];
			s16 swordY = m_player.y() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][1];
			
			playAnimation(swordX, swordY, m_player.direction());
		} else {
			s16 swordX = m_player.x() + swordPosition[m_player.direction()][6][0];
			s16 swordY = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			drawFrame(swordX, swordY, m_player.direction() + 8);
		}
	} else {
		s16 swordX = m_player.x() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][0];
		s16 swordY = m_player.y() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][1];
		
		playAnimation(swordX, swordY, m_player.direction());
	}
}

