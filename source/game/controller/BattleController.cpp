/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include <cmath>

// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
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

				// gk::AudioPlayer::playSound("sfx-enemyDie"); // FIXME: GAMEKIT
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

					gk::Vector2f pos1{receiverPosition.x, receiverPosition.y};
					gk::Vector2f pos2{attackerPosition.x, attackerPosition.y};

					gk::Vector2f v = pos1 - pos2;

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

