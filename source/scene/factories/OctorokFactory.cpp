/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 02:23:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "PlayerFactory.hpp"
#include "Sprite.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations& collisionInformations);

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject object;
	object.set<PositionComponent>(x, y, 16, 16);
	object.set<MovementComponent>(new OctorokMovement);
	
	auto &collisionComponent = object.set<CollisionComponent>();
	
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &object) {
		Map::currentMap->scene().checkCollisionsFor(object);
	});
	
	collisionComponent.addAction(&octorokAction);
	
	auto &spriteComponent = object.set<Sprite>("enemies-octorok", 16, 16);
	spriteComponent.addAnimation({4, 0}, 150);
	spriteComponent.addAnimation({5, 1}, 150);
	spriteComponent.addAnimation({6, 2}, 150);
	spriteComponent.addAnimation({7, 3}, 150);
	
	return object;
}

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations &collisionInformations) {
	if(Scene::isPlayer(object) && !collisionInformations.empty()) {
		auto &playerPosition = object.get<PositionComponent>();
		auto &octorokPosition = octorok.get<PositionComponent>();
		
		Vector2f v = playerPosition.position() - octorokPosition.position();
		
		if(v.x != 0) v.x /= abs(v.x);
		if(v.y != 0) v.y /= abs(v.y);
		
		// Player::player.hurt(1, vx, vy);
	}
}

