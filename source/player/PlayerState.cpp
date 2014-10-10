/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:24:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "HurtState.hpp"
#include "MovingState.hpp"
#include "PushingState.hpp"
#include "StandingState.hpp"
#include "SwordState.hpp"

PlayerState::PlayerState() : m_player(CharacterManager::player) {
}

PlayerState::~PlayerState() {
}

void PlayerState::move(double dx, double dy) {
	((Entity*)(&m_player))->move(dx, dy);
}

PlayerState *PlayerState::nextState() {
	PlayerState *currentState;
	
	switch(m_nextStateType) {
		case StateType::TypeHurt:
			currentState = new HurtState();
			break;
		case StateType::TypeMoving:
			currentState = new MovingState();
			break;
		case StateType::TypePushing:
			currentState = new PushingState();
			break;
		case StateType::TypeStanding:
			currentState = new StandingState();
			break;
		case StateType::TypeSword:
			currentState = new SwordState();
			break;
	}
	
	delete this;
	
	return currentState;
}

