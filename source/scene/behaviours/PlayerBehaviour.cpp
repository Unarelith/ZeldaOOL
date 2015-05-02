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
#include "GamePad.hpp"
#include "Map.hpp"
#include "PlayerBehaviour.hpp"
#include "SwordFactory.hpp"

#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void PlayerBehaviour::action(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &position = object.get<PositionComponent>();
	
	switch(m_state) {
		case State::Standing:
			if(GamePad::isKeyPressedOnce(GameKey::A)) {
				SceneObject sword = SwordFactory::create(position.x, position.y, position.direction, object);
				Map::currentMap->scene().addObject(std::move(sword));
			}
			
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
		case State::Hurt:
		case State::Standing:
			sprite.isAnimated = false;
			sprite.animID = static_cast<s8>(position.direction);
			sprite.frameID = 1;
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

