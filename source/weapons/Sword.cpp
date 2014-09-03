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
#include "Keyboard.hpp"
#include "PlayerState.hpp"
#include "Sword.hpp"

s16 swordPosition[4][7][2] = {
	{{-12,   0}, {-12,  12}, {-12,  12}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{  0, -12}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  0, -12}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 12,   0}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
};

Sword::Sword() : Weapon("graphics/animations/sword.png", 16, 16) {
	m_state = State::Swinging;
	
	addAnimation({0, 4, 4, 8, 8, 8}, 40);
	addAnimation({1, 5, 5, 9, 9, 9}, 40);
	addAnimation({2, 6, 6, 10, 10, 10}, 40);
	addAnimation({3, 7, 7, 11, 11, 11}, 40);
	
	m_tmpDirection = 0;
}

Sword::~Sword() {
}

void Sword::update() {
	switch(m_state) {
		case State::Swinging:
			if(animationAtEnd(m_player.direction())) {
				m_state = State::Loading;
				
				m_loadingTimer.reset();
				m_loadingTimer.start();
			}
			
			static bool keyReleased = false;
			if(!Keyboard::isKeyPressed(Keyboard::Key::A)) {
				keyReleased = true;
			}
			
			if(keyReleased && Keyboard::isKeyPressed(Keyboard::Key::A) && animationCurrentFrame(m_player.direction()) >= 4) {
				keyReleased = false;
				
				Sound::Effect::swordSlash1.play();
				
				m_player.resetAnimation(m_player.direction() + 8);
				resetAnimation(m_player.direction());
			}
			
			break;
		case State::Loading:
			if(!Keyboard::isKeyPressed(Keyboard::A)) {
				//if(m_loadingTimer.time() > 1000) {
				//	Sound::Effect::swordSpin.play();
				//	
				//	m_state = State::SpinAttack;
				//	
				//	m_tmpDirection = m_player.direction();
				//	
				//	m_player.turn();
				//	
					setColor(sf::Color(255, 255, 255));
				//} else {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				//}
			}
			break;
		default:
			break;
	}
}

void Sword::draw() {
	s16 swordX, swordY;
	
	switch(m_state) {
		case State::Swinging:
			swordX = m_player.x() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][0];
			swordY = m_player.y() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][1];
			
			playAnimation(swordX, swordY, m_player.direction());
			
			break;
		case State::Loading:
			if(m_loadingTimer.time() > 1000 && m_loadingTimer.time() % 200 > 100) {
				setColor(sf::Color(0, 0, 0));
			} else {
				setColor(sf::Color(255, 255, 255));
			}
			
			swordX = m_player.x() + swordPosition[m_player.direction()][6][0];
			swordY = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			drawFrame(swordX, swordY, m_player.direction() + 8);
			
			break;
		default:
			break;
	}
}

