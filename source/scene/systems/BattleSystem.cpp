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

#include "AudioPlayer.hpp"
#include "BattleSystem.hpp"
#include "HurtMovement.hpp"

#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void BattleSystem::update(SceneObject &object) {
	if(object.has<HealthComponent>() && object.has<MovementComponent>()) {
		auto &health = object.get<HealthComponent>();
		auto &movements = object.get<MovementComponent>().movements;
		
		if(health.isHurt && movements.size() != 0 && movements.top() && movements.top()->isFinished()) {
			health.isHurt = false;
			
			if(health.life > 0) {
				movements.pop();
			}
			else if(object.type() == "Monster") {
				health.isDead = true;
				
				if(object.has<HitboxComponent>()) {
					object.get<HitboxComponent>().resetCurrentHitbox();
				}
				
				if(object.has<SpriteComponent>()) {
					object.get<SpriteComponent>().isEnabled = false;
				}
				
				object.get<EffectsComponent>().enable("destroy");
				
				AudioPlayer::playEffect("enemyDie");
			}
		}
	}
}

void BattleSystem::hurt(SceneObject &attacker, SceneObject &receiver) {
	if(!attacker.has<HealthComponent>() || !attacker.get<HealthComponent>().isDead) {
		if(receiver.has<HealthComponent>()) {
			auto &receiverHealth = receiver.get<HealthComponent>();
			
			if(!receiverHealth.isHurt && !receiverHealth.isDead) {
				if(receiver.has<MovementComponent>()) {
					auto &attackerPosition = attacker.get<PositionComponent>();
					auto &receiverPosition = receiver.get<PositionComponent>();
					
					Vector2f v = receiverPosition.position() - attackerPosition.position();
					
					if(v.x != 0) v.x /= fabs(v.x);
					if(v.y != 0) v.y /= fabs(v.y);
					
					receiver.get<MovementComponent>().movements.push(new HurtMovement(v.x, v.y));
				}
				
				receiverHealth.isHurt = true;
				receiverHealth.life--;
			}
		}
	}
}

