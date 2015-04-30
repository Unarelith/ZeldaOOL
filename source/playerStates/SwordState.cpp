/*
 * =====================================================================================
 *
 *       Filename:  SwordState.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:25:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "SwordState.hpp"
#include "TilesData.hpp"

SwordState::SwordState(Sword *sword) {
	AudioPlayer::playEffect("swordSlash1");
	
	m_playerMoved = false;
	
	m_sword = sword;
}

SwordState::~SwordState() {
	m_character.unlockDirection();
	
	m_sword->reset();
}

void SwordState::move(double dx, double dy) {
	m_character.move(dx, dy);
	m_sword->move(dx, dy);
}

void SwordState::movePlayer(u8 direction, bool forward) {
	if(direction == Character::Direction::Left) {
		if(forward) m_character.move(-4, 0);
		else		m_character.move(4, 0);
	}
	else if(direction == Character::Direction::Right) {
		if(forward) m_character.move(4, 0);
		else		m_character.move(-4, 0);
	}
	else if(direction == Character::Direction::Up) {
		if(forward) m_character.move(0, -3);
		else		m_character.move(0, 3);
	}
	else if(direction == Character::Direction::Down) {
		if(forward) m_character.move(0, 3);
		else		m_character.move(0, -3);
	}
	
	m_playerMoved = true;
}

void SwordState::update() {
	if(m_sword->state() == Sword::State::Loading) {
		m_directionLocked = true;
		
		m_character.updateMovement();
	}
	
	m_sword->update();
	
	if(m_sword->state() != Sword::State::SpinAttack) {
		if(!m_playerMoved) {
			if(m_sword->animationCurrentFrame(m_character.direction()) == 1) {
				movePlayer(m_character.direction());
			}
			else if(m_sword->animationCurrentFrame(m_character.direction()) == 6) {
				movePlayer(m_character.direction(), false);
			}
		}
		else if((m_sword->animationCurrentFrame(m_character.direction()) != 1)
			 && (m_sword->animationCurrentFrame(m_character.direction()) != 6)) {
			m_playerMoved = false;
		}
	} else {
		if(!m_playerMoved && !(m_sword->animationCurrentFrame(8) & 1)) {
			u8 prevMovementDirection = 0;
			u8 movementDirection = 0;
			
			if(m_sword->animationCurrentFrame(8) % 8 == 0) {
				prevMovementDirection = Player::Direction::Right;
				movementDirection = Player::Direction::Down;
			}
			else if(m_sword->animationCurrentFrame(8) % 8 == 2) {
				prevMovementDirection = Player::Direction::Down;
				movementDirection = Player::Direction::Left;
			}
			else if(m_sword->animationCurrentFrame(8) % 8 == 4) {
				prevMovementDirection = Player::Direction::Left;
				movementDirection = Player::Direction::Up;
			}
			else if(m_sword->animationCurrentFrame(8) % 8 == 6) {
				prevMovementDirection = Player::Direction::Up;
				movementDirection = Player::Direction::Right;
			}
			
			if(m_sword->spinFrameCounter() != 0) {
				movePlayer(prevMovementDirection, false);
			}
			
			movePlayer(movementDirection);
		}
		else if(m_sword->animationCurrentFrame(8) & 1) {
			m_playerMoved = false;
		}
	}
}

void SwordState::render() {
	m_sword->draw();
	
	drawPlayer();
}

void SwordState::drawPlayer() {
	if(m_sword->state() == Sword::State::Swinging) {
		m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction() + 8);
	}
	else if(m_sword->state() == Sword::State::Loading
		&& (Keyboard::isKeyPressed(Keyboard::Left)
		 || Keyboard::isKeyPressed(Keyboard::Right)
		 || Keyboard::isKeyPressed(Keyboard::Up)
		 || Keyboard::isKeyPressed(Keyboard::Down))) {
		m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction());
	}
	else if(m_sword->state() == Sword::State::SpinAttack) {
		m_character.playAnimation(m_character.x(), m_character.y(), 12);
	} else {
		m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
	}
}

