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
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void collectableAction(SceneObject &collectable, SceneObject &object, CollisionInformations &collisionInformations);

SceneObject CollectableFactory::create(u16 x, u16 y, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType) {
	SceneObject object;
	object.set<MovementComponent>(new CollectableMovement(movementType));
	object.set<CollectableComponent>(soundEffectName);
	object.set<LifetimeComponent>(6000);
	
	auto &image = object.set<Image>("collectables-" + name);
	
	object.set<PositionComponent>(x + 7 - image.width() / 2, y + 8 - image.height() / 2, image.width(), image.height());
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&collectableAction);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(Hitbox(IntRect(2, 2, 3, 4)));
	
	return object;
}

SceneObject CollectableFactory::createHeart(u16 x, u16 y, CollectableMovement::Type movementType) {
	SceneObject object = create(x, y, "heart", "getHeart", movementType);
	object.get<CollectableComponent>().setAction([](SceneObject &) {
		// Player::player.addHearts(1);
	});
	
	return object;
}

SceneObject CollectableFactory::createRupees(u16 x, u16 y, RupeesAmount amount, CollectableMovement::Type movementType) {
	std::string name = "rupees" + std::to_string(amount);
	
	SceneObject object = create(x, y, name, (amount == RupeesAmount::One) ? "getRupee" : "getRupees5", movementType);
	object.get<CollectableComponent>().setAction([amount](SceneObject &) {
		// Player::player.inventory().addRupees(amount);
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

