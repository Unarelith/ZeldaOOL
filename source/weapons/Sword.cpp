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
	{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{ -5, -15}, {  8, -12}, {  8, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  5, -15}, { -8, -12}, { -8, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
};

s16 spinAttackPosition[8][2] = {
	{-1, 16}, {-6, 15}, {-15, 1}, {-12, -12}, {0, -15}, {11, -12}, {15, 2}, {13, 13}
};

Sword::Sword() : Weapon("graphics/animations/sword.png", 16, 16) {
	m_state = State::Swinging;
	
	// Swinging
	addAnimation({0, 4, 4, 8, 8, 8}, 40);
	addAnimation({1, 5, 5, 9, 9, 9}, 40);
	addAnimation({2, 6, 6, 10, 10, 10}, 40);
	addAnimation({3, 5, 5, 11, 11, 11}, 40);
	
	// Loading
	addAnimation({12, 8}, 60);
	addAnimation({13, 9}, 60);
	addAnimation({14, 10}, 60);
	addAnimation({15, 11}, 60);
	
	// SpinAttack
	addAnimation({8, 4, 10, 6, 11, 5, 9, 7}, 50);
	
	m_loaded = false;
	
	m_spinCurrentFrame = 0;
	m_spinFrameCounter = 0;
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
			
			if(keyReleased && Keyboard::isKeyPressed(Keyboard::Key::A)
			&& animationCurrentFrame(m_player.direction()) >= 4) {
				if(m_player.direction() == Character::Direction::Left) {
					m_player.move(4, 0);
				}
				else if(m_player.direction() == Character::Direction::Right) {
					m_player.move(-4, 0);
				}
				else if(m_player.direction() == Character::Direction::Up) {
					m_player.move(0, 3);
				}
				else if(m_player.direction() == Character::Direction::Down) {
					m_player.move(0, -3);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Left)) {
					m_player.setDirection(Character::Direction::Left);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Right)) {
					m_player.setDirection(Character::Direction::Right);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Up)) {
					m_player.setDirection(Character::Direction::Up);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Down)) {
					m_player.setDirection(Character::Direction::Down);
				}
				
				keyReleased = false;
				
				Sound::Effect::swordSlash1.play();
				
				m_player.resetAnimation(m_player.direction() + 8);
				resetAnimation(m_player.direction());
			}
			
			break;
		case State::Loading:
			if(m_loadingTimer.time() > 650 && !m_loaded) {
				m_loaded = true;
				
				Sound::Effect::swordCharge.play();
			}
			
			if(!Keyboard::isKeyPressed(Keyboard::A)) {
				if(m_loadingTimer.time() > 650) {
					Sound::Effect::swordSpin.play();
					
					m_loaded = false;
					
					m_state = State::SpinAttack;
					
					if(m_player.direction() == Character::Direction::Left) {
						m_spinCurrentFrame = 2;
					}
					else if(m_player.direction() == Character::Direction::Right) {
						m_spinCurrentFrame = 6;
					}
					else if(m_player.direction() == Character::Direction::Up) {
						m_spinCurrentFrame = 4;
					}
					else if(m_player.direction() == Character::Direction::Down) {
						m_spinCurrentFrame = 0;
					}
					
					resetAnimation(8, m_spinCurrentFrame);
					startAnimation(8);
					
					m_player.resetAnimation(12, m_spinCurrentFrame);
					m_player.startAnimation(12);
				} else {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			break;
		case State::SpinAttack:
			if(m_spinFrameCounter < 9) {
				if(m_spinCurrentFrame != animationCurrentFrame(8)) {
					m_spinCurrentFrame = animationCurrentFrame(8);
					
					m_spinFrameCounter++;
				}
			} else {
				m_animations[8].timer.stop();
				
				m_spinTimer.start();
				
				if(m_spinTimer.time() >= m_animations[8].delay) {
					if(m_player.direction() == Character::Direction::Left) {
						m_player.move(4, 0);
					}
					else if(m_player.direction() == Character::Direction::Right) {
						m_player.move(-4, 0);
					}
					else if(m_player.direction() == Character::Direction::Up) {
						m_player.move(0, 3);
					}
					else if(m_player.direction() == Character::Direction::Down) {
						m_player.move(0, -3);
					}
					
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			
			break;
		default:
			break;
	}
	
	switch(m_state) {
		case State::Swinging:
			m_x = m_player.x() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][0];
			m_y = m_player.y() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][1];
			
			break;
		case State::Loading:
			m_x = m_player.x() + swordPosition[m_player.direction()][6][0];
			m_y = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			break;
		case State::SpinAttack:
			m_x = m_player.x() + spinAttackPosition[animationCurrentFrame(8)][0];
			m_y = m_player.y() + spinAttackPosition[animationCurrentFrame(8)][1];
			
			break;
		default:
			break;
	}
}

void Sword::draw() {
	switch(m_state) {
		case State::Swinging:
			playAnimation(m_x, m_y, m_player.direction());
			break;
		case State::Loading:
			if(!m_loaded) {
				drawFrame(m_x, m_y, m_player.direction() + 8);
			} else {
				playAnimation(m_x, m_y, m_player.direction() + 4);
			}
			
			break;
		case State::SpinAttack:
			playAnimation(m_x, m_y, 8);
			break;
		default:
			break;
	}
}

