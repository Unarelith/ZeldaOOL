/*
 * =====================================================================================
 *
 *       Filename:  AbstractView.hpp
 *
 *    Description:
 *
 *        Created:  26/01/2018 00:41:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ABSTRACTVIEW_HPP_
#define ABSTRACTVIEW_HPP_

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "PositionComponent.hpp"
#include "RenderTarget.hpp"
#include "SceneObjectList.hpp"

class AbstractView {
	public:
		virtual void draw(const SceneObject &object, RenderTarget &target, RenderStates states) const = 0;

		virtual void draw(const SceneObjectList &objectList, RenderTarget &target, RenderStates states) const {
			for(auto &object : objectList) {
				draw(object, target, states);

				glm::mat4 modelMatrix;
				if (object.has<PositionComponent>()) {
					modelMatrix = glm::translate((states.modelMatrix) ? *states.modelMatrix : glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
					states.modelMatrix = &modelMatrix;
				}

				if (object.has<SceneObjectList>())
					draw(object.get<SceneObjectList>(), target, states);
			}
		}
};

#endif // ABSTRACTVIEW_HPP_
