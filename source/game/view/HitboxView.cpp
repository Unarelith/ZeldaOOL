/*
 * =====================================================================================
 *
 *       Filename:  HitboxView.cpp
 *
 *    Description:
 *
 *        Created:  21/04/2018 09:24:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <gk/gui/RectangleShape.hpp>
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
			rect.setSize(hitbox->width, hitbox->height);
			rect.setWireframeMode(true);
			rect.setColor(gk::Color::White);

			if(object.has<SpriteComponent>() && object.get<SpriteComponent>().hasCurrentState()) {
				auto pos = object.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
				rect.move(pos.x, pos.y);
			}

			target.draw(rect, states);
		}
	}
}

