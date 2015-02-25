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
#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"

void collectableAction(SceneObject &collectable, SceneObject &object, bool collision);

SceneObject CollectableFactory::create(u16 x, u16 y, const std::string &name) {
	SceneObject object;
	
	auto *image = object.setComponent<Image>("collectables-" + name);
	
	object.setComponent<PositionComponent>(x, y, image->width(), image->height());
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&collectableAction);
	
	// Add Collectable component to store:
	// - Sound effect name
	// - Action on link's inventory
	
	// Add a lifetime component
	// -> LifetimeSystem checks the lifetime and remove objets from their scene
	// -> DrawingSystem handles the disappearance
	
	return object;
}

SceneObject CollectableFactory::createRupees(u16 x, u16 y, RupeesAmount amount) {
	std::string name = "rupees" + std::to_string(static_cast<u8>(amount));
	
	SceneObject object = create(x, y, name);
	
	return object;
}

void collectableAction(SceneObject &collectable, SceneObject &object, bool collision) {
	if(Scene::isPlayer(object) && collision) {
		// Sound effect is loaded from CollectableComponent
		AudioPlayer::playEffect("getRupee");
		
		// Here execute collectable action on player
	}
}

