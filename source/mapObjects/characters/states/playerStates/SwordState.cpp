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
#include "GamePad.hpp"
#include "Map.hpp"
#include "SwordState.hpp"

SwordState::SwordState(Sword *sword) {
	AudioPlayer::playEffect("swordSlash1");
	
	m_playerMoved = false;
	
	m_sword = sword;
}

SwordState::~SwordState() {
	m_character.unlockDirection();
	
	m_sword->reset();
}

void SwordState::update() {
	if(m_sword->state() == Sword::State::Loading) {
		m_directionLocked = true;
		
		m_character.updateMovement();
	}
	
	m_sword->update();
}

void SwordState::render() {
	m_sword->draw();
	
	drawPlayer();
}

void SwordState::drawPlayer() {
	if(m_sword->state() == Sword::State::Swinging) {
		m_character.playAnimation(m_character.x(false), m_character.y(false), m_character.direction() + 8);
	}
	else if(m_sword->state() == Sword::State::Loading && m_character.isMoving()) {
		m_character.playAnimation(m_character.x(false), m_character.y(false), m_character.direction());
	}
	else if(m_sword->state() == Sword::State::SpinAttack) {
		m_character.playAnimation(m_character.x(false), m_character.y(false), 12);
	} else {
		m_character.drawFrame(m_character.x(false), m_character.y(false), m_character.direction());
	}
}

