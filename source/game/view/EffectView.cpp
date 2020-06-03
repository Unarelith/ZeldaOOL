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

