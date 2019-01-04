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
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "EffectsComponent.hpp"
#include "EffectView.hpp"
#include "PositionComponent.hpp"

void EffectView::draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) {
	if (object.has<EffectsComponent>()) {
		if (object.has<PositionComponent>()) {
			states.transform.translate(object.get<PositionComponent>().x, object.get<PositionComponent>().y);
		}

		auto &effects = object.get<EffectsComponent>().effects();
		for(auto &it : effects) {
			if(it.second.isEnabled) {
				if(it.second.hasAnimations()) {
					if (it.second.currentAnimation().isFinished())
						it.second.isEnabled = false;

					it.second.setAnimated(true);
					it.second.setCurrentAnimation(0);
				} else {
					it.second.setAnimated(false);
					it.second.setCurrentFrame(0);
				}

				it.second.updateAnimations();
				it.second.setPosition(it.second.offset.x, it.second.offset.y);
				target.draw(it.second, states);
			}
		}
	}
}

