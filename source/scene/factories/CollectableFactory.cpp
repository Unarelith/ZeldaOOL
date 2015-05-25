/*
 * =====================================================================================
 *
 *       Filename:  CollectableFactory.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:43:37
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "CollectableFactory.hpp"
#include "ResourceHandler.hpp"
#include "Scene.hpp"
#include "Texture.hpp"

#include "Image.hpp"
#include "CollectableComponent.hpp"
#include "CollisionComponent.hpp"
#include "InventoryComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void collectableAction(SceneObject &collectable, SceneObject &object, CollisionInformations &collisionInformations);

SceneObject CollectableFactory::create(Vector2f position, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType) {
	SceneObject object;
	object.set<MovementComponent>(new CollectableMovement(movementType));
	object.set<CollectableComponent>(soundEffectName);
	object.set<LifetimeComponent>(6000);
	
	auto &image = object.set<Image>("collectables-" + name);
	
	object.set<PositionComponent>(position.x + 7 - image.width() / 2, position.y + 8 - image.height() / 2, image.width(), image.height());
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&collectableAction);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(Hitbox(IntRect(0, 0, image.width(), image.height())));
	
	return object;
}

SceneObject CollectableFactory::createHeart(Vector2f position, CollectableMovement::Type movementType) {
	SceneObject object = create(position, "heart", "getHeart", movementType);
	object.get<CollectableComponent>().setAction([](SceneObject &) {
		// Player::player.addHearts(1);
	});
	
	return object;
}

SceneObject CollectableFactory::createRupees(Vector2f position, RupeesAmount amount, CollectableMovement::Type movementType) {
	std::string name = "rupees" + std::to_string(amount);
	
	SceneObject object = create(position, name, (amount == RupeesAmount::One) ? "getRupee" : "getRupees5", movementType);
	object.get<CollectableComponent>().setAction([amount](SceneObject &player) {
		player.get<InventoryComponent>().addRupees(amount);
	});
	
	return object;
}

void collectableAction(SceneObject &collectable, SceneObject &object, CollisionInformations &collisionInformations) {
	auto &collectableComponent = collectable.get<CollectableComponent>();
	auto &lifetimeComponent = collectable.get<LifetimeComponent>();
	
	if(Scene::isPlayer(object) && !collisionInformations.empty()) {
		AudioPlayer::playEffect(collectableComponent.soundEffectName());
		
		collectableComponent.action(object);
		
		lifetimeComponent.kill();
	}
}

