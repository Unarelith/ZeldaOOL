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
#include "Keyboard.hpp"
#include "EffectManager.hpp"
#include "SwordState.hpp"

SwordState::SwordState() {
	m_stateType = StateType::TypeSword;
	m_nextStateType = StateType::TypeSword;
	
	Sound::Effect::swordSlash1.play();
	
	m_playerMoved = false;
}

SwordState::~SwordState() {
}

void SwordState::update() {
	m_sword.update();
	
	if(!m_playerMoved) {
		if(m_sword.animationCurrentFrame(m_player.direction()) == 1) {
			if(m_player.direction() == Character::Direction::Left) {
				m_player.move(-4, 0);
			}
			else if(m_player.direction() == Character::Direction::Right) {
				m_player.move(4, 0);
			}
			else if(m_player.direction() == Character::Direction::Up) {
				m_player.move(0, -3);
			}
			else if(m_player.direction() == Character::Direction::Down) {
				m_player.move(0, 3);
			}
			
			m_playerMoved = true;
		}
		else if(m_sword.animationCurrentFrame(m_player.direction()) == 3) {
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
			
			m_playerMoved = true;
		}
	} else {
		if((m_sword.animationCurrentFrame(m_player.direction()) != 1)
		&& (m_sword.animationCurrentFrame(m_player.direction()) != 3)) {
			m_playerMoved = false;
		}
	}
	
	if(m_sword.state() == Sword::State::Loading) {
		m_directionLocked = true;
		
		move();
	}
}

void SwordState::draw() {
	m_sword.draw();
	
	drawPlayer();
}

void SwordState::drawPlayer() {
	if(m_sword.state() == Sword::State::Swinging) {
		m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 8);
	}
	else if(m_sword.state() == Sword::State::Loading
		&& (Keyboard::isKeyPressed(Keyboard::Left)
		 || Keyboard::isKeyPressed(Keyboard::Right)
		 || Keyboard::isKeyPressed(Keyboard::Up)
		 || Keyboard::isKeyPressed(Keyboard::Down))) {
		m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction());
	} else {
		m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
	}
	
	EffectManager::drawEffects(&m_player);
}

