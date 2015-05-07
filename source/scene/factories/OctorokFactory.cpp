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

void octorokAction(SceneObject &octorok, SceneObject &object, bool collision);

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

void octorokAction(SceneObject &octorok, SceneObject &object, bool collision) {
	if(Scene::isPlayer(object) && collision) {
		auto &playerPosition = object.get<PositionComponent>();
		auto &octorokPosition = octorok.get<PositionComponent>();
		
		s16 vx = playerPosition.x - octorokPosition.x;
		s16 vy = playerPosition.y - octorokPosition.y;
		
		if(vx != 0) vx /= abs(vx);
		if(vy != 0) vy /= abs(vy);
		
		// Player::player.hurt(1, vx, vy);
	}
}

