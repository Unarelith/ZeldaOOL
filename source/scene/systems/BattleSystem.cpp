/*
 * =====================================================================================
 *
 *       Filename:  BattleSystem.cpp
 *
 *    Description:  
 *
 *        Created:  26/05/2015 12:43:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include "BattleSystem.hpp"
#include "HurtMovement.hpp"

#include "HealthComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void BattleSystem::update(SceneObject &object) {
	if(object.has<HealthComponent>() && object.has<MovementComponent>()) {
		auto &health = object.get<HealthComponent>();
		auto &movements = object.get<MovementComponent>().movements;
		
		if(!movements.empty() && movements.top() && movements.top()->isFinished()) {
			movements.pop();
			
			health.isHurt = false;
		}
	}
}

void BattleSystem::hurt(SceneObject &attacker, SceneObject &receiver) {
	if(receiver.has<HealthComponent>()) {
		auto &receiverHealth = receiver.get<HealthComponent>();
		
		if(!receiverHealth.isHurt) {
			if(receiver.has<MovementComponent>()) {
				auto &attackerPosition = attacker.get<PositionComponent>();
				auto &receiverPosition = receiver.get<PositionComponent>();
				
				Vector2f v = receiverPosition.position() - attackerPosition.position();
				
				if(v.x != 0) v.x /= fabs(v.x);
				if(v.y != 0) v.y /= fabs(v.y);
				
				receiver.get<MovementComponent>().movements.emplace(new HurtMovement(v.x, v.y));
			}
			
			receiverHealth.isHurt = true;
			receiverHealth.life--;
		}
	}
}

