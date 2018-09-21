/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:24:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePadMovement.hpp"
#include "PlayerBehaviour.hpp"
#include "PlayerFactory.hpp"
#include "PlayerMapCollisionAction.hpp"
#include "ResourceHandler.hpp"
#include "SceneObjectList.hpp"
#include "ScrollingTransition.hpp"
#include "TilesInfos.hpp"
#include "TransitionState.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "InventoryComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject player{"Link", "Player"};
	player.set<SpriteComponent>(ResourceHandler::getInstance().get<SpriteComponent>("sprite-characters-link"));
	player.set<BehaviourComponent>(new PlayerBehaviour);
	player.set<HealthComponent>(13 * 4, 11 * 4);
	player.set<MovementComponent>(new GamePadMovement);
	player.set<CollisionComponent>().addAction(PlayerMapCollisionAction());
	player.set<SceneObjectList>();

	auto &positionComponent = player.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = Direction::Down;

	auto &hitboxComponent = player.set<HitboxComponent>();
	hitboxComponent.addHitbox(4, 5, 8, 10);

	auto &effectsComponent = player.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	Sprite &effect = effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16, {0, 8});
	effect.addAnimation({{0, 1, 2}, 150});

	auto &inventoryComponent = player.set<InventoryComponent>();
	inventoryComponent.addWeapon("swordL1");
	inventoryComponent.addWeapon("strengthL1");
	inventoryComponent.equipWeapon(0, 0, GameKey::A);
	inventoryComponent.equipWeapon(0, 1, GameKey::B);

	return player;
}

