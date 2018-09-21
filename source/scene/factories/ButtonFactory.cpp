/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 01:50:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ButtonFactory.hpp"
#include "Scene.hpp"

#include "ButtonComponent.hpp"
#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

void buttonAction(SceneObject &button, SceneObject &object, bool inCollision);

SceneObject ButtonFactory::create(u16 tileX, u16 tileY) {
	SceneObject button{"Button", "Tile"};
	button.set<ButtonComponent>();
	button.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &hitboxComponent = button.set<HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 8);

	auto &collisionComponent = button.set<CollisionComponent>();
	collisionComponent.addAction(&buttonAction);

	return button;
}

void buttonAction(SceneObject &button, SceneObject &object, bool inCollision) {
	if(object.type() == "Player") {
		auto &positionComponent = button.get<PositionComponent>();
		auto &buttonComponent = button.get<ButtonComponent>();

		if(inCollision) {
			buttonComponent.pressedAction(positionComponent.x / 16,
			                              positionComponent.y / 16);
		} else {
			buttonComponent.releasedAction(positionComponent.x / 16,
			                               positionComponent.y / 16);
		}
	}
}

