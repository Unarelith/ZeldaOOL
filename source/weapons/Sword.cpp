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
	addAnimation({12, 8}, 80);
	addAnimation({13, 9}, 80);
	addAnimation({14, 10}, 80);
	addAnimation({15, 11}, 80);
	
	// SpinAttack
	addAnimation({8, 4, 10, 6, 11, 5, 9, 7, 8}, 40);
	
	m_tmpDirection = 0;
	
	m_loaded = false;
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
						resetAnimation(8, 2);
						startAnimation(8);
						
						m_player.resetAnimation(12, 2);
						m_player.startAnimation(12);
					}
					else if(m_player.direction() == Character::Direction::Right) {
						resetAnimation(8, 6);
						startAnimation(8);
						
						m_player.resetAnimation(12, 6);
						m_player.startAnimation(12);
					}
					else if(m_player.direction() == Character::Direction::Up) {
						resetAnimation(8, 4);
						startAnimation(8);
						
						m_player.resetAnimation(12, 4);
						m_player.startAnimation(12);
					}
					else if(m_player.direction() == Character::Direction::Down) {
						resetAnimation(8, 0);
						startAnimation(8);
						
						m_player.resetAnimation(12);
						m_player.startAnimation(12);
					}
				} else {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			break;
		case State::SpinAttack:
			if(m_player.direction() == Character::Direction::Left) {
				if(animationCurrentFrame(8) == 1) {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			else if(m_player.direction() == Character::Direction::Right) {
				if(animationCurrentFrame(8) == 5) {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			else if(m_player.direction() == Character::Direction::Up) {
				if(animationCurrentFrame(8) == 3) {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
			}
			else if(m_player.direction() == Character::Direction::Down) {
				if(animationAtEnd(8)) {
					m_player.setNextStateType(PlayerState::StateType::TypeStanding);
				}
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
			swordX = m_player.x() + swordPosition[m_player.direction()][6][0];
			swordY = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			if(!m_loaded) {
				drawFrame(swordX, swordY, m_player.direction() + 8);
			} else {
				playAnimation(swordX, swordY, m_player.direction() + 4);
			}
			
			break;
		case State::SpinAttack:
			swordX = m_player.x() + spinAttackPosition[animationCurrentFrame(8)][0];
			swordY = m_player.y() + spinAttackPosition[animationCurrentFrame(8)][1];
			
			playAnimation(swordX, swordY, 8);
			
			break;
		default:
			break;
	}
}

