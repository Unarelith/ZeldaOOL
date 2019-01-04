/*
 * =====================================================================================
 *
 *       Filename:  SpriteView.cpp
 *
 *    Description:
 *
 *        Created:  26/01/2018 01:30:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <gk/scene/component/MovementComponent.hpp>
#include <gk/system/GameClock.hpp>

#include "HealthComponent.hpp"
#include "Image.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "SpriteView.hpp"

void SpriteView::draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) {
	// if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
	// 	return;

	if(object.has<LifetimeComponent>()) {
		auto &lifetime = object.get<LifetimeComponent>();
		if(lifetime.almostDead() && (lifetime.dead(object) || lifetime.aliveTime() % 120 <= 59)) return;
	}

	if (object.has<PositionComponent>()) {
		states.transform.translate(object.get<PositionComponent>().x, object.get<PositionComponent>().y);
	}

	if(object.has<Image>()) {
		target.draw(object.get<Image>(), states);
	}

	// FIXME: Remove this (only used for Octorok)
	if(object.has<Sprite>()) {
		// auto &sprite = object.get<Sprite>();
		// sprite.updateAnimations();
		// target.draw(sprite, states);

		if(!object.has<HealthComponent>() || !object.get<HealthComponent>().isDead) {
			bool animated = false;
			u16 animID = 0;

			if(object.has<gk::MovementComponent>()) {
				animated = object.get<gk::MovementComponent>().isMoving;
			}

			if(object.get<PositionComponent>().direction != Direction::None) {
				animID += static_cast<s8>(object.get<PositionComponent>().direction);
			}

			auto &sprite = object.get<Sprite>();
			sprite.setCurrentAnimation(animID);
			sprite.setAnimated(animated);

			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt
			&& gk::GameClock::getTicks() % 100 < 50) {
				sprite.setPaletteID(1);
			}

			sprite.updateAnimations();
			target.draw(sprite, states);

			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt) {
				sprite.setPaletteID(0);
			}
		}
	}

	if(object.has<SpriteComponent>()) {
		auto &spriteComponent = object.get<SpriteComponent>();
		if (spriteComponent.isEnabled()) {
			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt
			&& gk::GameClock::getTicks() % 100 < 50) {
				spriteComponent.sprite().setPaletteID(1);
			}

			spriteComponent.updateAnimations();
			target.draw(spriteComponent.sprite(), states);

			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt) {
				spriteComponent.sprite().setPaletteID(0);
			}
		}
	}
}

