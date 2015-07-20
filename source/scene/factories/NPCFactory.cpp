/*
 * =====================================================================================
 *
 *       Filename:  NPCFactory.cpp
 *
 *    Description:  
 *
 *        Created:  22/06/2015 12:53:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "MessageBoxState.hpp"
#include "NPCFactory.hpp"
#include "Scene.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void npcAction(SceneObject &npc, SceneObject &object, bool inCollision);

SceneObject NPCFactory::create(u16 tileX, u16 tileY) {
	SceneObject npc;
	npc.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	
	auto &hitboxComponent = npc.set<HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 8);
	
	auto &collisionComponent = npc.set<CollisionComponent>();
	collisionComponent.addAction(&npcAction);
	
	auto &spriteComponent = npc.set<SpriteComponent>("characters-blueBoy", 16, 16);
	spriteComponent.isAnimated = true;
	
	spriteComponent.sprite.addAnimation({0, 4}, 150);
	spriteComponent.sprite.addAnimation({1, 5}, 150);
	spriteComponent.sprite.addAnimation({2, 6}, 150);
	spriteComponent.sprite.addAnimation({3, 7}, 150);
	
	return npc;
}

#include "MovementComponent.hpp"

void npcAction(SceneObject &npc, SceneObject &object, bool inCollision) {
	if(Scene::isPlayer(object) && inCollision) {
		// FIXME: Improve collisions
		auto &playerPosition = object.get<PositionComponent>();
		auto &playerMovement = object.get<MovementComponent>();
		
		auto &npcPosition = npc.get<PositionComponent>();
		
		if(playerPosition.intersectionDirection(npcPosition) == 1) {
			playerMovement.v.x = 0;
		} else {
			playerMovement.v.y = 0;
		}
		
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			ApplicationStateStack::getInstance().push<MessageBoxState>("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.", ApplicationStateStack::getInstance().top());
		}
	}
}

