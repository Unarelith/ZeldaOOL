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
#include <glm/gtc/matrix_transform.hpp>

#include "HitboxComponent.hpp"
#include "HitboxView.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "RectangleShape.hpp"
#include "SpriteComponent.hpp"

void HitboxView::draw(const SceneObject &object, RenderTarget &target, RenderStates states) {
	if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
		return;

	glm::mat4 modelMatrix;
	if (object.has<PositionComponent>()) {
		modelMatrix = glm::translate((states.modelMatrix) ? *states.modelMatrix : glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
		states.modelMatrix = &modelMatrix;
	}

	if (object.has<HitboxComponent>()) {
		const IntRect *hitbox = object.get<HitboxComponent>().currentHitbox();
		if(hitbox) {
			RectangleShape rect;
			rect.setPosition(hitbox->x, hitbox->y);
			rect.setSize(hitbox->width, hitbox->height);
			rect.setWireframeMode(true);
			rect.setColor(Color::white);

			if(object.has<SpriteComponent>()) {
				u16 animID = object.get<SpriteComponent>().animID;
				auto pos = object.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition();
				rect.move(pos.x, pos.y);
			}

			target.draw(rect, states);
		}
	}
}

