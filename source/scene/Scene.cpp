/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:34:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Network.hpp>

#include "CollisionComponent.hpp"
#include "CollisionHelper.hpp"
#include "Scene.hpp"

SceneObject *Scene::player = nullptr;

void Scene::reset() {
	for (auto &controller : m_controllerList) {
		if (controller->isGlobal())
			controller->reset(m_objects);
		controller->reset(*Scene::player);
	}

	for (SceneObject &object : m_objects) {
		for (auto &controller : m_controllerList) {
			if (!controller->isGlobal()) {
				controller->reset(object);

				if (object.has<SceneObjectList>())
					controller->reset(object.get<SceneObjectList>());
			}
		}
	}
}

void Scene::update() {
	for (auto &controller : m_controllerList) {
		if (controller->isGlobal())
			controller->update(m_objects);
		controller->update(*Scene::player);
	}

	for (SceneObject &object : m_objects) {
		for (auto &controller : m_controllerList) {
			if (!controller->isGlobal()) {
				controller->update(object);

				if (object.has<SceneObjectList>())
					controller->update(object.get<SceneObjectList>());
			}
		}
	}
}

void Scene::draw(RenderTarget &target, RenderStates states) const {
	for (auto &view : m_viewList) {
		view->draw(m_objects, target, states);
		view->draw(*Scene::player, target, states);
	}
}

SceneObject &Scene::addObject(SceneObject &&object) {
	SceneObject &obj = m_objects.addObject(std::move(object));

	if(obj.has<CollisionComponent>()) {
		obj.get<CollisionComponent>().addChecker([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}

	return obj;
}

void Scene::addCollisionChecker(std::function<void(SceneObject &)> checker) {
	for (SceneObject &object : m_objects) {
		if (object.has<CollisionComponent>()) {
			object.get<CollisionComponent>().addChecker(checker);
		}
	}
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(SceneObject &object2 : m_objects) {
		if(&object != &object2) {
			CollisionHelper::checkCollision(object, object2);

			if (object.has<SceneObjectList>())
				for (SceneObject &child : object.get<SceneObjectList>())
					CollisionHelper::checkCollision(child, object2);

			if (object2.has<SceneObjectList>())
				for (SceneObject &child : object2.get<SceneObjectList>())
					CollisionHelper::checkCollision(object, child);
		}
	}
}

