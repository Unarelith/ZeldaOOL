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
#include "SceneObjectList.hpp"
#include "SwordFactory.hpp"

#include "BehaviourComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void PlayerBehaviour::action(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &position = player.get<PositionComponent>();
	auto &objects = player.get<SceneObjectList>();
	
	if(m_state == "Standing") {
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			m_sword = &objects.addObject(SwordFactory::create(position.x, position.y, position.direction, player));
			m_state = "Sword";
		}
		
		if(movement.isMoving) {
			m_state = "Moving";
		}
	}
	else if(m_state == "Moving") {
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			m_sword = &objects.addObject(SwordFactory::create(position.x, position.y, position.direction, player));
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
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			m_sword = &objects.addObject(SwordFactory::create(position.x, position.y, position.direction, player));
			m_state = "Sword";
		}
		
		if(!movement.isBlocked) {
			m_state = "Standing";
		}
	}
	else if(m_state == "Sword") {
		std::string swordState = m_sword->get<BehaviourComponent>().behaviour->state();
		
		if(swordState == "Swinging") {
			movement.movement.reset(nullptr);
		}
		else if(swordState == "Loading") {
			movement.movement.reset(new GamePadMovement(true));
		}
		else if(swordState == "SpinAttack") {
			movement.movement.reset(nullptr);
		}
		else if(swordState == "Finished") {
			m_sword->get<LifetimeComponent>().kill();
			m_sword = nullptr;
			DEBUG("KILL")
			movement.movement.reset(new GamePadMovement);
			
			m_state = "Standing";
		}
	} else {
		throw EXCEPTION("Unknown player state:", m_state);
	}
	
	updateSprite(player);
}

void PlayerBehaviour::updateSprite(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &position = player.get<PositionComponent>();
	auto &sprite = player.get<SpriteComponent>();
	
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
		} else {
			sprite.isAnimated = false;
			sprite.animID = static_cast<s8>(position.direction);
			sprite.frameID = 1;
		}
	}
}

