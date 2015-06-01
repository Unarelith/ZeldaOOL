/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:58:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GameClock.hpp"
#include "DrawingSystem.hpp"
#include "RectangleShape.hpp"

#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	if(object.has<PositionComponent>()) {
		auto &position = object.get<PositionComponent>();
		
		if(object.has<LifetimeComponent>()) {
			auto &lifetime = object.get<LifetimeComponent>();
			if(lifetime.almostDead() && (lifetime.dead(object) || lifetime.aliveTime() % 120 <= 59)) return;
		}
		
		if(object.has<Image>()) {
			object.get<Image>().draw(position.x, position.y);
		}
		
		if(object.has<Sprite>()) {
			drawSprite(object, position.x, position.y);
		}
		
		if(object.has<SpriteComponent>()) {
			drawSpriteComponent(object, position.x, position.y);
		}
		
		if(object.has<EffectsComponent>()) {
			drawEffects(object, position.x, position.y);
		}
		
		if(object.has<HitboxComponent>()) {
			drawHitbox(object, position.x, position.y);
		}
	}
}

void DrawingSystem::drawEffects(SceneObject &object, float x, float y) {
	auto &effects = object.get<EffectsComponent>().effects();
	
	for(auto &it : effects) {
		if(it.second.isEnabled) {
			if(it.second.hasAnimations()) {
				it.second.playAnimation(x + it.second.offset.x, y + it.second.offset.y, 0);
			} else {
				it.second.drawFrame(x + it.second.offset.x, y + it.second.offset.y, 0);
			}
		}
	}
}

void DrawingSystem::drawHitbox(SceneObject &object, float x, float y) {
	auto &hitboxComponent = object.get<HitboxComponent>();
	
	static RectangleShape rect;
	
	const IntRect *hitbox = hitboxComponent.currentHitbox();
	if(hitbox) {
		rect.setPosition(x + hitbox->x, y + hitbox->y);
		rect.resize(hitbox->width, hitbox->height);
		
		if(object.has<SpriteComponent>()) {
			u16 animID = object.get<SpriteComponent>().animID;
				rect.move(object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition().x,
						  object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition().y);
		}
		
		if(object.has<std::string>() && object.get<std::string>() == "Sword") {
			rect.draw(Color::red, true);
		} else {
			rect.draw(Color::white, true);
		}
	}
}

void DrawingSystem::drawSprite(SceneObject &object, float x, float y) {
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
		
		if(object.has<HealthComponent>()
		&& object.get<HealthComponent>().isHurt
		&& GameClock::getTicks() % 150 < 75) {
			sprite.setPaletteID(1);
		}
		
		if(animated) {
			sprite.playAnimation(x, y, animID);
		} else {
			sprite.drawFrame(x, y, animID);
		}
		
		if(object.has<HealthComponent>()
		&& object.get<HealthComponent>().isHurt) {
			sprite.setPaletteID(0);
		}
	}
}

void DrawingSystem::drawSpriteComponent(SceneObject &object, float x, float y) {
	auto &spriteComponent = object.get<SpriteComponent>();
	
	if(spriteComponent.isEnabled) {
		if(object.has<HealthComponent>()
		&& object.get<HealthComponent>().isHurt
		&& GameClock::getTicks() % 150 < 75) {
			spriteComponent.sprite.setPaletteID(1);
		}
		
		if(spriteComponent.isAnimated) {
			spriteComponent.sprite.playAnimation(x, y, spriteComponent.animID);
		} else {
			spriteComponent.sprite.currentAnimation().stop();
			
			spriteComponent.sprite.drawAnimationFrame(x, y, spriteComponent.animID, spriteComponent.frameID);
		}
		
		if(object.has<HealthComponent>()
		&& object.get<HealthComponent>().isHurt) {
			spriteComponent.sprite.setPaletteID(0);
		}
	}
}

