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
#include "GamePadMovement.hpp"
#include "Map.hpp"
#include "PlayerBehaviour.hpp"
#include "SwordFactory.hpp"

#include "BehaviourComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void PlayerBehaviour::action(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &position = object.get<PositionComponent>();
	
	if(m_state == "Standing") {
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			SceneObject sword = SwordFactory::create(position.x, position.y, position.direction, object);
			m_sword = &Map::currentMap->scene().addObject(std::move(sword));
			
			m_state = "Sword";
		}
		
		if(movement.isMoving) {
			m_state = "Moving";
		}
	}
	else if(m_state == "Moving") {
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			SceneObject sword = SwordFactory::create(position.x, position.y, position.direction, object);
			m_sword = &Map::currentMap->scene().addObject(std::move(sword));
			
			m_state = "Sword";
		}
		
		if(!movement.isMoving) {
			m_state = "Standing";
		}
		
		if(movement.isBlocked) {
			m_state = "Pushing";
		}
	}
	else if(m_state == "Pushing") {
		if(!movement.isBlocked) {
			m_state = "Standing";
		}
	}
	else if(m_state == "Sword") {
		auto &movementComponent = object.get<MovementComponent>();
		
		std::string swordState;
		if(m_sword->has<BehaviourComponent>()) {
			swordState = m_sword->get<BehaviourComponent>().behaviour->state();
		} else {
			// m_sword->debug();
			throw EXCEPTION("Problem in sword components");
		}
		
		
		if(swordState == "Swinging") {
			movementComponent.movement.reset(nullptr);
		}
		else if(swordState == "Loading") {
			movementComponent.movement.reset(new GamePadMovement(true));
		}
		else if(swordState == "SpinAttack") {
			movementComponent.movement.reset(nullptr);
		}
		else if(swordState == "Finished") {
			m_sword->get<LifetimeComponent>().kill();
			
			movementComponent.movement.reset(new GamePadMovement);
			
			m_state = "Standing";
		}
	}
	else {
		throw EXCEPTION("Unknown player state:", m_state);
	}
	
	updateSprite(object);
}

void PlayerBehaviour::updateSprite(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &position = object.get<PositionComponent>();
	auto &sprite = object.get<SpriteComponent>();
	
	if(m_state == "Hurt" || m_state == "Standing") {
		sprite.isAnimated = false;
		sprite.animID = static_cast<s8>(position.direction);
		sprite.frameID = 1;
	}
	else if(m_state == "Moving") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(position.direction);
	}
	else if(m_state == "Pushing") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(position.direction) + 4;
	}
	else if(m_state == "Sword") {
		std::string swordState = m_sword->get<BehaviourComponent>().behaviour->state();
		
		if(swordState == "Swinging") {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction) + 8;
		}
		else if(swordState == "Loading" && movement.isMoving) {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction);
		}
		else if(swordState == "SpinAttack") {
			sprite.isAnimated = true;
			sprite.animID = 12;
		}
		else {
			sprite.isAnimated = false;
			sprite.animID = static_cast<s8>(position.direction);
			sprite.frameID = 1;
		}
	}
}

