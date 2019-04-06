/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 01:50:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "ButtonComponent.hpp"
#include "ButtonFactory.hpp"
#include "PositionComponent.hpp"

gk::SceneObject ButtonFactory::create(u16 tileX, u16 tileY) {
	gk::SceneObject button{"Button", "Tile"};
	button.set<ButtonComponent>();
	button.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &hitboxComponent = button.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 8);

	auto &collisionComponent = button.set<gk::CollisionComponent>();
	collisionComponent.addAction(&ButtonFactory::buttonAction);

	return button;
}

void ButtonFactory::buttonAction(gk::SceneObject &button, gk::SceneObject &object, bool inCollision) {
	if(object.type() == "Player") {
		auto &positionComponent = button.get<PositionComponent>();
		auto &buttonComponent = button.get<ButtonComponent>();

		if(inCollision) {
			buttonComponent.pressedAction(positionComponent.left / 16,
			                              positionComponent.top / 16);
		} else {
			buttonComponent.releasedAction(positionComponent.left / 16,
			                               positionComponent.top / 16);
		}
	}
}

