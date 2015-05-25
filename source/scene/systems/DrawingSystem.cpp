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
#include "DrawingSystem.hpp"

#include "EffectsComponent.hpp"
#include "HitboxesComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

#include "RectangleShape.hpp"

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
		
		if(object.has<HitboxesComponent>()) {
			drawHitboxes(object, position.x, position.y);
		}
	}
}

void DrawingSystem::drawEffects(SceneObject &object, float x, float y) {
	auto &effects = object.get<EffectsComponent>().effects();
	
	for(auto &it : effects) {
		if(it.second.second) {
			if(it.second.first.hasAnimations()) {
				it.second.first.playAnimation(x, y, 0);
			} else {
				it.second.first.drawFrame(x, y, 0);
			}
		}
	}
}

void DrawingSystem::drawHitboxes(SceneObject &object, float x, float y) {
	auto &hitboxes = object.get<HitboxesComponent>();
	static RectangleShape rect;
	
	for(auto &hitbox : hitboxes) {
		if(hitbox.isEnabled) {
			rect.setPosition(x + hitbox.rect.x, y + hitbox.rect.y);
			rect.resize(hitbox.rect.width, hitbox.rect.height);
			
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
}

void DrawingSystem::drawSprite(SceneObject &object, float x, float y) {
	bool animated = false;
	u16 animID = 0;
	
	if(object.has<MovementComponent>()) {
		animated = object.get<MovementComponent>().isMoving;
	}
	
	if(object.get<PositionComponent>().direction != Direction::None) {
		animID += static_cast<s8>(object.get<PositionComponent>().direction);
	}
	
	if(animated) {
		object.get<Sprite>().playAnimation(x, y, animID);
	} else {
		object.get<Sprite>().drawFrame(x, y, animID);
	}
}

void DrawingSystem::drawSpriteComponent(SceneObject &object, float x, float y) {
	auto &sprite = object.get<SpriteComponent>();
	
	if(!sprite.isDisabled) {
		if(sprite.isAnimated) {
			sprite.sprite.playAnimation(x, y, sprite.animID);
		} else {
			sprite.sprite.drawAnimationFrame(x, y, sprite.animID, sprite.frameID);
		}
	}
}

