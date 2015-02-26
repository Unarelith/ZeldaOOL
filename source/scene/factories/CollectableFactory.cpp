/*
 * =====================================================================================
 *
 *       Filename:  CollectableFactory.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 23:25:28
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
#include "PositionComponent.hpp"

void collectableAction(SceneObject &collectable, SceneObject &object, bool collision);

SceneObject CollectableFactory::create(u16 x, u16 y, const std::string &name, const std::string &soundEffectName) {
	SceneObject object;
	object.setComponent<CollectableComponent>(soundEffectName);
	object.setComponent<LifetimeComponent>(6000);
	
	auto *image = object.setComponent<Image>("collectables-" + name);
	
	object.setComponent<PositionComponent>(x, y, image->width(), image->height());
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&collectableAction);
	
	return object;
}

SceneObject CollectableFactory::createRupees(u16 x, u16 y, RupeesAmount amount) {
	std::string name = "rupees" + std::to_string(static_cast<u8>(amount));
	
	SceneObject object = create(x, y, name, (amount == RupeesAmount::One) ? "getRupee" : "getRupees5");
	object.getComponent<CollectableComponent>()->setAction([](SceneObject &player) {
		// TODO: Add rupees to player here
	});
	
	return object;
}

void collectableAction(SceneObject &collectable, SceneObject &object, bool collision) {
	auto *collectableComponent = collectable.getComponent<CollectableComponent>();
	auto *lifetimeComponent = collectable.getComponent<LifetimeComponent>();
	
	if(Scene::isPlayer(object) && collision && collectableComponent) {
		AudioPlayer::playEffect(collectableComponent->soundEffectName());
		
		collectableComponent->action(object);
		
		lifetimeComponent->kill();
	}
}

