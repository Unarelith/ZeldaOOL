/*
 * =====================================================================================
 *
 *       Filename:  BattleController.cpp
 *
 *    Description:
 *
 *        Created:  26/05/2015 12:43:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include <gk/resource/AudioPlayer.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "BattleController.hpp"
#include "HurtMovement.hpp"

#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void BattleController::update(gk::SceneObject &object) {
	if(object.has<HealthComponent>() && object.has<gk::MovementComponent>()) {
		auto &health = object.get<HealthComponent>();
		auto &movements = object.get<gk::MovementComponent>().movements;

		if(health.isHurt && movements.size() != 0 && movements.top() && movements.top()->isFinished()) {
			health.isHurt = false;

			if(health.life() > 0) {
				movements.pop();
			}
			else if(object.type() == "Monster") {
				health.isDead = true;

				if(object.has<gk::HitboxComponent>()) {
					object.get<gk::HitboxComponent>().resetCurrentHitbox();
				}

				if(object.has<SpriteComponent>()) {
					object.get<SpriteComponent>().setEnabled(false);
				}

				object.get<EffectsComponent>().enable("destroy");

				gk::AudioPlayer::playSound("sfx-enemyDie");
			}
		}
	}
}

void BattleController::hurt(gk::SceneObject &attacker, gk::SceneObject &receiver) {
	if(!attacker.has<HealthComponent>() || !attacker.get<HealthComponent>().isDead) {
		if(receiver.has<HealthComponent>()) {
			auto &receiverHealth = receiver.get<HealthComponent>();

			if(!receiverHealth.isHurt && !receiverHealth.isDead) {
				if(receiver.has<gk::MovementComponent>()) {
					auto &attackerPosition = attacker.get<PositionComponent>();
					auto &receiverPosition = receiver.get<PositionComponent>();

					sf::Vector2f pos1{receiverPosition.left, receiverPosition.top};
					sf::Vector2f pos2{attackerPosition.left, attackerPosition.top};

					sf::Vector2f v = pos1 - pos2;

					if(v.x != 0) v.x /= fabs(v.x);
					if(v.y != 0) v.y /= fabs(v.y);

					receiver.get<gk::MovementComponent>().movements.push(new HurtMovement(v.x, v.y));
				}

				receiverHealth.isHurt = true;
				receiverHealth.removeLife(1);
			}
		}
	}
}

