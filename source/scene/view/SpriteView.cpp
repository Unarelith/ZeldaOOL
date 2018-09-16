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
#include <glm/gtc/matrix_transform.hpp>

#include "GameClock.hpp"
#include "HealthComponent.hpp"
#include "Image.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "SpriteView.hpp"

void SpriteView::draw(const SceneObject &object, RenderTarget &target, RenderStates states) {
	if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
		return;

	// 	if(object.has<LifetimeComponent>()) {
	// 		auto &lifetime = object.get<LifetimeComponent>();
	// 		if(lifetime.almostDead() && (lifetime.dead(object) || lifetime.aliveTime() % 120 <= 59)) return;
	// 	}

	glm::mat4 modelMatrix;
	if (object.has<PositionComponent>()) {
		modelMatrix = glm::translate((states.modelMatrix) ? *states.modelMatrix : glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
		states.modelMatrix = &modelMatrix;
	}

	if(object.has<Image>()) {
		target.draw(object.get<Image>(), states);
	}

	if(object.has<Sprite>()) {
		// auto &sprite = object.get<Sprite>();
		// sprite.updateAnimations();
		// target.draw(sprite, states);

		if(!object.has<HealthComponent>() || !object.get<HealthComponent>().isDead) {
			bool animated = false;
			u16 animID = 0;

			if(object.has<MovementComponent>()) {
				animated = object.get<MovementComponent>().isMoving;
			}

			if(object.get<PositionComponent>().direction != Direction::None) {
				animID += static_cast<s8>(object.get<PositionComponent>().direction);
			}

			auto &sprite = object.get<Sprite>();
			sprite.setCurrentAnimation(animID);
			sprite.setAnimated(animated);

			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt
			&& GameClock::getTicks() % 100 < 50) {
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
		// auto &spriteComponent = object.get<SpriteComponent>();
		// spriteComponent.updateAnimations();
		// target.draw(spriteComponent.sprite, states);

		auto &spriteComponent = object.get<SpriteComponent>();
		if(spriteComponent.isEnabled) {
			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt
			&& GameClock::getTicks() % 100 < 50) {
				spriteComponent.sprite.setPaletteID(1);
			}

			spriteComponent.sprite.setAnimated(spriteComponent.isAnimated);
			spriteComponent.sprite.setCurrentAnimation(spriteComponent.animID);
			if(!spriteComponent.isAnimated) {
				spriteComponent.sprite.setCurrentFrame(spriteComponent.sprite.currentAnimation().getFrame(spriteComponent.frameID));
			}

			spriteComponent.sprite.updateAnimations();
			target.draw(spriteComponent.sprite, states);

			if(object.has<HealthComponent>()
			&& object.get<HealthComponent>().isHurt) {
				spriteComponent.sprite.setPaletteID(0);
			}
		}
	}
}

// void DrawingSystem::drawEffects(SceneObject &object, float x, float y) {
// 	auto &effects = object.get<EffectsComponent>().effects();
//
// 	for(auto &it : effects) {
// 		if(it.second.isEnabled) {
// 			if(it.second.hasAnimations()) {
// 				it.second.playAnimation(x + it.second.offset.x, y + it.second.offset.y, 0);
// 			} else {
// 				it.second.drawFrame(x + it.second.offset.x, y + it.second.offset.y, 0);
// 			}
// 		}
// 	}
// }
//
// void DrawingSystem::drawHitbox(SceneObject &object, float x, float y) {
// 	auto &hitboxComponent = object.get<HitboxComponent>();
//
// 	static RectangleShape rect;
//
// 	const IntRect *hitbox = hitboxComponent.currentHitbox();
// 	if(hitbox) {
// 		rect.setPosition(x + hitbox->x, y + hitbox->y);
// 		rect.resize(hitbox->width, hitbox->height);
//
// 		if(object.has<SpriteComponent>()) {
// 			u16 animID = object.get<SpriteComponent>().animID;
// 				rect.move(object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition().x,
// 						  object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition().y);
// 		}
//
// 		if(object.has<std::string>() && object.get<std::string>() == "Sword") {
// 			rect.draw(Color::red, true);
// 		} else {
// 			rect.draw(Color::white, true);
// 		}
// 	}
// }

