/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:47:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "StandingState.hpp"
#include "MovingState.hpp"
#include "PushingState.hpp"

PlayerState::PlayerState() : m_player(CharacterManager::player) {
}

PlayerState::~PlayerState() {
}

PlayerState *PlayerState::nextState() {
	PlayerState *currentState;
	
	switch(m_nextStateType) {
		case StateType::TypeStanding:
			currentState = new StandingState();
			break;
		case StateType::TypeMoving:
			currentState = new MovingState();
			break;
		case StateType::TypePushing:
			currentState = new PushingState();
			break;
	}
	
	delete this;
	
	return currentState;
}

