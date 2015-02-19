/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 01:50:40
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ButtonFactory.hpp"
#include "CollisionComponent.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"

SceneObject ButtonFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	
	auto positionComponent = object.setComponent<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	positionComponent->hitbox.reset(4, 4, 8, 4);
	
	auto collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction([](SceneObject &button, SceneObject &) {
		PositionComponent *buttonPosition = button.getComponent<PositionComponent>();
		
		Map::currentMap->setTile(buttonPosition->x / 16,
		                         buttonPosition->y / 16, 8);
	});
	
	return object;
}

