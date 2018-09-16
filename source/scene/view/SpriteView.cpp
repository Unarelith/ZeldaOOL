/*
 * =====================================================================================
 *
 *       Filename:  SpriteView.cpp
 *
 *    Description:
 *
 *        Created:  26/01/2018 01:30:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <glm/gtc/matrix_transform.hpp>

#include "Image.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "SpriteView.hpp"

void SpriteView::draw(const SceneObject &object, RenderTarget &target, RenderStates states) {
	if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
		return;

	glm::mat4 modelMatrix;
	if (object.has<PositionComponent>()) {
		modelMatrix = glm::translate(glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
		states.modelMatrix = &modelMatrix;
	}

	if(object.has<Image>()) {
		target.draw(object.get<Image>(), states);
	}

	if(object.has<Sprite>()) {
		auto &sprite = object.get<Sprite>();
		sprite.updateAnimations();
		target.draw(sprite, states);
	}

	if(object.has<SpriteComponent>()) {
		auto &spriteComponent = object.get<SpriteComponent>();
		// spriteComponent.updateAnimations(); // FIXME
		target.draw(spriteComponent.sprite, states);
	}
}

