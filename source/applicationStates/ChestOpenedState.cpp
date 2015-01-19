/*
 * =====================================================================================
 *
 *       Filename:  ChestOpenedState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 00:58:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "ChestOpenedState.hpp"
#include "DialogState.hpp"
#include "Map.hpp"
#include "SoundEffect.hpp"

ChestOpenedState::ChestOpenedState(ApplicationState *parent, float x, float y, Collectable *collectable) : ApplicationState(parent) {
	m_state = State::Opening;
	
	m_collectable = collectable;
	m_collectable->setPosition(x + 7 - m_collectable->width() / 2, y + 8);
	
	m_movementCounter = 0;
	
	m_speed = 0.125f;
	
	Sprite::pause = true;
}

void ChestOpenedState::update() {
	if(m_state == State::Opening) {
		m_collectable->move(0, -m_speed);
		
		m_movementCounter += m_speed;
		
		if(m_movementCounter > 7) {
			m_state = State::Opened;
		}
	}
	
	if(m_state == State::Opened) {
		SoundEffect::play("itemNew");
		
		m_collectable->action();
		
		// FIXME: TO IMPROVE
		m_stateStack->push<DialogState>(this, "Vous obtenez [2]30 [2]Rubis[0]!\nC'est bien.");
		
		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;
		
		m_stateStack->pop();
	}
}

void ChestOpenedState::render() {
	m_parent->render();
	
	if(m_state == State::Opening || (m_state == State::Finished && m_stateStack->size() > 1)) {
		m_collectable->draw();
	}
}

