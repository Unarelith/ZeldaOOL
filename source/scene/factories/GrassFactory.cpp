/*
 * =====================================================================================
 *
 *       Filename:  GrassFactory.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 20:33:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "EasyBehaviour.hpp"
#include "GrassFactory.hpp"
#include "Map.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "HitboxesComponent.hpp"

void grassAction(SceneObject &grass, SceneObject &object, CollisionInformations &collisionInformations);

SceneObject GrassFactory::create(u16 tileX, u16 tileY, bool lowGrass) {
	SceneObject object;
	
	object.set<PositionComponent>(tileX * 16 - 8, tileY * 16 - 8, 16, 16);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect(12, 12, 8, 8));
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&grassAction);
	
	auto &spriteComponent = object.set<SpriteComponent>("animations-grassDestroy", 32, 32);
	spriteComponent.isAnimated = true;
	spriteComponent.isDisabled = true;
	
	spriteComponent.sprite.addAnimation({0, 1, 2, 3, 4, 5}, 50);
	
	if(lowGrass) {
		spriteComponent.sprite.setColorMod(Color(255, 255, 255, 127));
	}
	
	// isCutted flag
	object.set<BehaviourComponent>(new EasyBehaviour([](SceneObject &object) {
		auto &spriteComponent = object.get<SpriteComponent>();
		
		if(spriteComponent.sprite.currentAnimation().isFinished()) {
			spriteComponent.sprite.currentAnimation().reset();
			spriteComponent.isDisabled = true;
		}
	},
	[](SceneObject &object) {
		auto &hitboxesComponent = object.get<HitboxesComponent>();
		hitboxesComponent.enableHitboxes();
	}));
	
	return object;
}

#include "AudioPlayer.hpp"
#include "CollectableFactory.hpp"

#include "WeaponComponent.hpp"

void grassAction(SceneObject &grass, SceneObject &object, CollisionInformations &collisionInformations) {
	
	if(!collisionInformations.empty() && object.has<WeaponComponent>()) {
		auto &grassSpriteComponent = grass.get<SpriteComponent>();
		auto &grassHitboxesComponent = grass.get<HitboxesComponent>();
		
		auto &weaponComponent = object.get<WeaponComponent>();
		
		if(Scene::isPlayer(weaponComponent.owner)
		&& grassSpriteComponent.isDisabled && grassHitboxesComponent.isHitboxesEnable()) {
			auto &grassPosition = grass.get<PositionComponent>();
			auto &playerDirection = weaponComponent.owner.get<PositionComponent>().direction;
			auto &swordSprite = object.get<SpriteComponent>().sprite;
			
			if((object.get<BehaviourComponent>().behaviour->state() == "Swinging"
			 && swordSprite.getAnimation((s8)playerDirection).framesDisplayed() > 2
			 && swordSprite.getAnimation((s8)playerDirection).framesDisplayed() < swordSprite.getAnimation((s8)playerDirection).size())
			|| object.get<BehaviourComponent>().behaviour->state() == "SpinAttack") {
				AudioPlayer::playEffect("grassDestroy");
				
				if(rand() % 5 == 0) {
					Map::currentMap->scene().addObject(CollectableFactory::createRupees(grassPosition.x + 8, grassPosition.y + 8, RupeesAmount::One, CollectableMovement::Type::Dropped));
				}
				else if(rand() % 15 == 7) {
					Map::currentMap->scene().addObject(CollectableFactory::createHeart(grassPosition.x + 8, grassPosition.y + 8, CollectableMovement::Type::Dropped));
				}
				else if(rand() % 25 == 11) {
					Map::currentMap->scene().addObject(CollectableFactory::createRupees(grassPosition.x + 8, grassPosition.y + 8, RupeesAmount::Five, CollectableMovement::Type::Dropped));
				}
				else if(rand() % 250 == 176) {
					Map::currentMap->scene().addObject(CollectableFactory::createRupees(grassPosition.x + 8, grassPosition.y + 8, RupeesAmount::Thirty, CollectableMovement::Type::Dropped));
				}
				
				Map::currentMap->setTile((grassPosition.x + 8) / 16,
				                         (grassPosition.y + 8) / 16, 36);
				
				grassSpriteComponent.isDisabled = false;
				grassHitboxesComponent.disableHitboxes();
			}
		}
	}
}

