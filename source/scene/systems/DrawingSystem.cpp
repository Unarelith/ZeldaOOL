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

#include "HitboxesComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

#include "RectangleShape.hpp"

void DrawingSystem::draw(SceneObject &object) {
	if(object.has<PositionComponent>()) {
		auto &positionComponent = object.get<PositionComponent>();
		
		if(object.has<LifetimeComponent>()) {
			auto &lifetime = object.get<LifetimeComponent>();
			if(lifetime.almostDead() && (lifetime.dead(object) || lifetime.aliveTime() % 120 <= 59)) return;
		}
		
		if(object.has<Image>()) {
			object.get<Image>().draw(positionComponent.position());
		}
		
		if(object.has<Sprite>()) {
			drawSprite(object, positionComponent.position());
		}
		
		if(object.has<SpriteComponent>()) {
			drawSpriteComponent(object, positionComponent.position());
		}
		
		if(object.has<HitboxesComponent>()) {
			auto &hitboxes = object.get<HitboxesComponent>();
			static RectangleShape rect;
			
			for(auto& hitbox : hitboxes) {
				if(hitbox.isEnabled) {
					rect.setPosition(positionComponent.position() + hitbox.rect.position());
					rect.resize(hitbox.rect.width, hitbox.rect.height);
					
					if(object.has<SpriteComponent>()) {
						u16 animID = object.get<SpriteComponent>().animID;
						rect.move(object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition());
					}
					
					if(object.has<std::string>() && object.get<std::string>() == "Sword") {
						rect.draw(Color::red, true);
					} else {
						rect.draw(Color::white, true);
					}
				}
			}
		}
	}
}

void DrawingSystem::drawSprite(SceneObject &object, Vector2f position) {
	bool animated = false;
	u16 animID = 0;
	
	if(object.has<MovementComponent>()) {
		animated = object.get<MovementComponent>().isMoving;
	}
	
	if(object.get<PositionComponent>().direction != Direction::None) {
		animID += static_cast<s8>(object.get<PositionComponent>().direction);
	}
	
	if(animated) {
		object.get<Sprite>().playAnimation(position, animID);
	} else {
		object.get<Sprite>().drawFrame(position, animID);
	}
}

void DrawingSystem::drawSpriteComponent(SceneObject &object, Vector2f position) {
	auto &sprite = object.get<SpriteComponent>();
	
	if(!sprite.isDisabled) {
		if(sprite.isAnimated) {
			sprite.sprite.playAnimation(position, sprite.animID);
		} else {
			sprite.sprite.currentAnimation().stop();
			sprite.sprite.drawAnimationFrame(position, sprite.animID, sprite.frameID);
		}
	}
}

