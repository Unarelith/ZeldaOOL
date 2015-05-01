/*
 * =====================================================================================
 *
 *       Filename:  ChestOpenedState.cpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 00:58:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "ChestOpenedState.hpp"
#include "DialogState.hpp"

ChestOpenedState::ChestOpenedState(ApplicationState *parent, float x, float y, Collectable &collectable) : ApplicationState(parent) {
	m_collectable = &collectable;
	m_collectable->setPosition(x + 7 - m_collectable->width() / 2, y + 8);
	
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
		AudioPlayer::playEffect("itemNew");
		
		m_collectable->action();
		
		// FIXME: TO IMPROVE (avoid the '[2]' repetition)
		m_stateStack->push<DialogState>(this, "Vous obtenez [2]30 [2]Rubis[0]!\nC'est bien.");
		
		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;
		
		m_stateStack->pop();
	}
}

void ChestOpenedState::draw() {
	m_parent->draw();
	
	if(m_state == State::Opening || (m_state == State::Finished && m_stateStack->size() > 1)) {
		m_collectable->draw();
	}
}

