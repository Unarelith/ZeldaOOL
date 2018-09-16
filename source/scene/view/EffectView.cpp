/*
 * =====================================================================================
 *
 *       Filename:  EffectView.cpp
 *
 *    Description:
 *
 *        Created:  16/09/2018 23:56:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <glm/gtc/matrix_transform.hpp>

#include "EffectsComponent.hpp"
#include "EffectView.hpp"
#include "PositionComponent.hpp"

void EffectView::draw(const SceneObject &object, RenderTarget &target, RenderStates states) {
	if (object.has<EffectsComponent>()) {
		glm::mat4 modelMatrix;
		if (object.has<PositionComponent>()) {
			modelMatrix = glm::translate((states.modelMatrix) ? *states.modelMatrix : glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
			states.modelMatrix = &modelMatrix;
		}

		auto &effects = object.get<EffectsComponent>().effects();
		for(auto &it : effects) {
			if(it.second.isEnabled) {
				if(it.second.hasAnimations()) {
					if (it.second.currentAnimation().isFinished())
						it.second.isEnabled = false;

					it.second.setAnimated(true);
					it.second.setPosition(it.second.offset.x, it.second.offset.y);
					it.second.setCurrentAnimation(0);
				} else {
					it.second.setAnimated(false);
					it.second.setPosition(it.second.offset.x, it.second.offset.y);
					it.second.setCurrentFrame(0);
				}

				it.second.updateAnimations();
				target.draw(it.second, states);
			}
		}
	}
}

