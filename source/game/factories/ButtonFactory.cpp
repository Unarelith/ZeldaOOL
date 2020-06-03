/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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
			buttonComponent.pressedAction(positionComponent.x / 16,
			                              positionComponent.y / 16);
		} else {
			buttonComponent.releasedAction(positionComponent.x / 16,
			                               positionComponent.y / 16);
		}
	}
}

