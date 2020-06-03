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
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <gk/graphics/RectangleShape.hpp>
#include <gk/scene/component/HitboxComponent.hpp>

#include "HitboxView.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void HitboxView::draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) {
	if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
		return;

	if (object.has<PositionComponent>()) {
		states.transform.translate(object.get<PositionComponent>().x, object.get<PositionComponent>().y);
	}

	if (object.has<gk::HitboxComponent>()) {
		const gk::FloatRect *hitbox = object.get<gk::HitboxComponent>().currentHitbox();
		if(hitbox) {
			gk::RectangleShape rect;
			rect.setPosition(hitbox->x, hitbox->y);
			rect.setSize(hitbox->sizeX, hitbox->sizeY);
			rect.setWireframeMode(true);
			rect.setFillColor(gk::Color::White);

			if(object.has<SpriteComponent>() && object.get<SpriteComponent>().hasCurrentState()) {
				auto pos = object.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
				rect.move(pos.x, pos.y);
			}

			target.draw(rect, states);
		}
	}
}

