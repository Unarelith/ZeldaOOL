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
#include "WeaponFactory.hpp"

#include "BehaviourComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

void PlayerBehaviour::action(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	
	if(m_state == "Standing") {
		if(movement.isMoving) m_state = "Moving";
		
		weaponAction(player);
	}
	else if(m_state == "Moving") {
		if(!movement.isMoving) m_state = "Standing";
		if(movement.isBlocked) m_state = "Pushing";
		
		weaponAction(player);
	}
	else if(m_state == "Pushing") {
		if(!movement.isBlocked) m_state = "Standing";
		
		weaponAction(player);
	}
	else if(m_state == "Sword") {
		std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
		if(swordState == "Swinging" || swordState == "SpinAttack") {
			movement.movement.reset(nullptr);
		}
		else if(swordState == "Loading") {
			movement.movement.reset(new GamePadMovement(true));
		}
		else if(swordState == "Finished") {
			m_weapon->get<LifetimeComponent>().kill();
			m_weapon = nullptr;
			
			movement.movement.reset(new GamePadMovement);
			
			m_state = "Standing";
		}
	} else {
		throw EXCEPTION("Unknown player state:", m_state);
	}
	
	updateSprite(player);
}

void PlayerBehaviour::weaponAction(SceneObject &player) {
	auto &positionComponent = player.get<PositionComponent>();
	auto &objects = player.get<SceneObjectList>();
	
	Weapon *weapon = nullptr;
	GameKey key;
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		weapon = player.get<InventoryComponent>().getWeaponA();
		key = GameKey::A;
	}
	else if(GamePad::isKeyPressedOnce(GameKey::B)) {
		weapon = player.get<InventoryComponent>().getWeaponB();
		key = GameKey::B;
	}
	
	if(weapon) {
		m_weapon = &objects.addObject(WeaponFactory::create(*weapon, positionComponent.position(), key, player));
		m_state = m_weapon->get<WeaponComponent>().playerState;
	}
}

void PlayerBehaviour::updateSprite(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &positionComponent = player.get<PositionComponent>();
	auto &sprite = player.get<SpriteComponent>();
	
	if(m_state == "Hurt" || m_state == "Standing") {
		sprite.isAnimated = false;
		sprite.animID = static_cast<s8>(positionComponent.direction);
		sprite.frameID = 1;
	}
	else if(m_state == "Moving") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(positionComponent.direction);
	}
	else if(m_state == "Pushing") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(positionComponent.direction) + 4;
	}
	else if(m_state == "Sword") {
		std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
		
		if(swordState == "Swinging") {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(positionComponent.direction) + 8;
		}
		else if(swordState == "Loading" && movement.isMoving) {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(positionComponent.direction);
		}
		else if(swordState == "SpinAttack") {
			sprite.isAnimated = true;
			sprite.animID = 12;
		} else {
			sprite.isAnimated = false;
			sprite.animID = static_cast<s8>(positionComponent.direction);
			sprite.frameID = 1;
		}
	}
}

