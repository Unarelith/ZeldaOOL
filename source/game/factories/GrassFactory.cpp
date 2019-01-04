/*
 * =====================================================================================
 *
 *       Filename:  GrassFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 20:33:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>

#include "EasyBehaviour.hpp"
#include "GrassFactory.hpp"
#include "Map.hpp"

#include "BehaviourComponent.hpp"
#include "LootComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

gk::SceneObject GrassFactory::create(u16 tileX, u16 tileY, bool lowGrass) {
	gk::SceneObject object{"Grass", "Tile"};
	object.set<PositionComponent>(tileX * 16 - 8, tileY * 16 - 8, 16, 16);

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(14, 14, 4, 4);

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addAction(&GrassFactory::grassAction);

	auto &spriteComponent = object.set<SpriteComponent>("animations-grassDestroy", 32, 32);
	spriteComponent.sprite().addAnimation({{0, 1, 2, 3, 4, 5}, 50});
	spriteComponent.addState("Default", false, true, 0, 0);
	spriteComponent.setState("Default", object);
	spriteComponent.setEnabled(false);

	if(lowGrass) {
		spriteComponent.sprite().setColor(gk::Color{255, 255, 255, 127});
	}

	object.set<BehaviourComponent>(new EasyBehaviour([](gk::SceneObject &object) {
		auto &spriteComponent = object.get<SpriteComponent>();

		if(spriteComponent.sprite().currentAnimation().isFinished()) {
			spriteComponent.sprite().currentAnimation().reset();
			spriteComponent.setEnabled(false);
		}
	},
	[](gk::SceneObject &object) {
		object.get<gk::HitboxComponent>().setCurrentHitbox(0);
	}));

	auto &lootComponent = object.set<LootComponent>();
	lootComponent.addItem(0.2,    CollectableType::Rupees, RupeesAmount::One);
	lootComponent.addItem(0.067,  CollectableType::Heart);
	lootComponent.addItem(0.04,   CollectableType::Rupees, RupeesAmount::Five);
	lootComponent.addItem(0.004,  CollectableType::Rupees, RupeesAmount::Thirty);
	lootComponent.addItem(0.0001, CollectableType::Rupees, RupeesAmount::Hundred);

	return object;
}

#include <gk/audio/AudioPlayer.hpp>
#include "WeaponComponent.hpp"
#include "World.hpp"

void GrassFactory::grassAction(gk::SceneObject &grass, gk::SceneObject &object, bool inCollision) {
	if(inCollision && object.has<WeaponComponent>()) {
		auto &grassHitboxComponent = grass.get<gk::HitboxComponent>();
		auto &grassSpriteComponent = grass.get<SpriteComponent>();

		auto &weaponOwner = object.get<WeaponComponent>().owner;

		if(weaponOwner.type() == "Player"
		&& object.name() == "Sword"
		&& !grassSpriteComponent.isEnabled()
		&& grassHitboxComponent.currentHitbox()) {
			auto &grassPosition = grass.get<PositionComponent>();
			auto &playerDirection = weaponOwner.get<PositionComponent>().direction;
			auto &swordSprite = object.get<SpriteComponent>().sprite();

			if((object.get<BehaviourComponent>().behaviour->state() == "Swinging"
			 && swordSprite.getAnimation((s8)playerDirection).displayedFramesAmount() > 2
			 && swordSprite.getAnimation((s8)playerDirection).displayedFramesAmount() < swordSprite.getAnimation((s8)playerDirection).size())
			|| object.get<BehaviourComponent>().behaviour->state() == "SpinAttack") {
				gk::AudioPlayer::playSound("sfx-grassDestroy");

				grass.get<LootComponent>().dropItem(grassPosition.x + 8, grassPosition.y + 8);

				World::getInstance().currentMap()->setTile((grassPosition.x + 8) / 16,
				                                           (grassPosition.y + 8) / 16, 36);

				grassSpriteComponent.setEnabled(true);
				grassHitboxComponent.resetCurrentHitbox();
			}
		}
	}
}

