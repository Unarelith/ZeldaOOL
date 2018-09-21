/*
 * =====================================================================================
 *
 *       Filename:  TileMapView.cpp
 *
 *    Description:
 *
 *        Created:  21/04/2018 09:29:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "TileMap.hpp"
#include "TileMapView.hpp"

void TileMapView::draw(const SceneObject &object, RenderTarget &target, RenderStates states) {
	if (object.has<LifetimeComponent>() && object.get<LifetimeComponent>().dead(object))
		return;

	glm::mat4 modelMatrix;
	if (object.has<PositionComponent>()) {
		modelMatrix = glm::translate((states.modelMatrix) ? *states.modelMatrix : glm::mat4{1}, glm::vec3{object.get<PositionComponent>().x, object.get<PositionComponent>().y, 0});
		states.modelMatrix = &modelMatrix;
	}

	if(object.has<TileMap>()) {
		auto &tileMap = object.get<TileMap>();
		tileMap.updateAnimations();
		target.draw(tileMap, states);
	}
}

