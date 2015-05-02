/*
 * =====================================================================================
 *
 *       Filename:  PlayerBehaviour.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 12:42:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "PlayerBehaviour.hpp"

#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void PlayerBehaviour::action(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	
	switch(m_state) {
		case State::Standing:
			if(movement.isMoving) {
				m_state = State::Moving;
			}
			
			break;
		case State::Moving:
			if(!movement.isMoving) {
				m_state = State::Standing;
			}
			
			if(movement.isBlocked) {
				m_state = State::Pushing;
			}
			
			break;
		case State::Pushing:
			if(!movement.isBlocked) {
				m_state = State::Standing;
			}
			
			break;
		case State::Hurt:
			break;
		case State::Sword:
			break;
	}
	
	updateSprite(object);
}

void PlayerBehaviour::updateSprite(SceneObject &object) {
	auto &position = object.get<PositionComponent>();
	auto &sprite = object.get<SpriteComponent>();
	
	switch(m_state) {
		case State::Standing:
		case State::Hurt:
			sprite.isAnimated = false;
			sprite.frameID = static_cast<s8>(position.direction);
			break;
		case State::Moving:
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction);
			break;
		case State::Pushing:
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction) + 4;
			break;
		case State::Sword:
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction) + 8;
			break;
	}
}

