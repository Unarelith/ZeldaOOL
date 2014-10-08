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
#include "GameStateManager.hpp"
#include "Map.hpp"
#include "Sound.hpp"

ChestOpenedState::ChestOpenedState(GameState *parent, float x, float y, Collectable *collectable) : GameState(parent) {
	m_state = State::Opening;
	
	m_collectable = collectable;
	m_collectable->setPosition(x + 7 - m_collectable->width() / 2, y + 8);
	
	m_movementCounter = 0;
	
	m_speed = 0.125f;
	
	Sprite::pause = true;
}

ChestOpenedState::~ChestOpenedState() {
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
		Sound::Effect::itemNew.play();
		
		m_collectable->action();
		
		GameStateManager::push(new DialogState(GameStateManager::top(), "Vous obtenez [2]30 [2]Rubis[0]!\nC'est bien."));
		
		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;
		
		GameStateManager::pop();
	}
}

void ChestOpenedState::render() {
	m_parent->render();
	
	if(m_state == State::Opening || (m_state == State::Finished && GameStateManager::size() > 1)) {
		m_collectable->draw();
	}
}

