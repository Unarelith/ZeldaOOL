/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 22:49:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Scene.hpp"

void Scene::update() {
	for(auto &it : m_objects) {
		it->update();
	}
}

void Scene::draw() {
	for(auto &it : m_objects) {
		it->draw();
	}
}

void Scene::removeObject(MapObject &object) {
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(),
					[&](std::unique_ptr<MapObject> &it) {
						return it.get() == &object;
					}), m_objects.end());
}

bool Scene::objectAtPosition(MapObject &obj, float x, float y) {
	return((floor(obj.x() / 8) == floor(x / 8)
		 || floor(obj.x() / 8) == floor(x / 8) - 1)
		&& (floor(obj.y() / 8) == floor(y / 8)
		 || floor(obj.y() / 8) == floor(y / 8) - 1));
}

MapObject *Scene::getObject(float x, float y) {
	for(auto &it : m_objects) {
		if(objectAtPosition(*it, x, y)) {
			return it.get();
		}
	}
	
	return nullptr;
}

void Scene::checkCollisionsFor(MapObject *object) {
	for(auto &it : m_objects) {
		MapObject *object2 = (it && it.get() != object) ? it.get() : &Player::player;
		
		if(object->inCollisionWith(*object2)) {
			object->collisionAction(*object2);
			object2->collisionAction(*object);
		}
	}
}

