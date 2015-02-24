/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 15:44:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "ChestOpeningState.hpp"
#include "MessageBoxState.hpp"
#include "Sprite.hpp"

ChestOpeningState::ChestOpeningState(ApplicationState *parent) : ApplicationState(parent) {
	Sprite::pause = true;
}

void ChestOpeningState::update() {
	if(m_state == State::Opening) {
	}
	else if(m_state == State::Opened) {
		AudioPlayer::playEffect("itemNew");
		
		ApplicationStateStack::getInstance().push<MessageBoxState>("Vous obtenez [2]30 Rubis[0]!\nC'est bien.", this);
		
		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;
		
		ApplicationStateStack::getInstance().pop();
	}
}

void ChestOpeningState::draw() {
	m_parent->draw();
}

