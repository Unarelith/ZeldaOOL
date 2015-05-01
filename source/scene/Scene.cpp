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
#include "CollisionComponent.hpp"
#include "CollisionSystem.hpp"
#include "LifetimeSystem.hpp"
#include "MovementSystem.hpp"
#include "DrawingSystem.hpp"
#include "Scene.hpp"

SceneObject *Scene::player = nullptr;

void Scene::update() {
	for(auto &it : m_oldObjects) {
		it->update();
	}
	
	LifetimeSystem::process(m_objects);
	
	for(auto &it : m_objects) {
		MovementSystem::process(it);
	}
	
	if(player) MovementSystem::process(*player);
}

void Scene::draw() {
	for(auto &it : m_oldObjects) {
		it->draw();
	}
	
	for(auto &it : m_objects) {
		DrawingSystem::draw(it);
	}
	
	if(player) DrawingSystem::draw(*player);
}

SceneObject &Scene::addObject(SceneObject &&object) {
	m_objects.push_back(std::move(object));
	
	if(m_objects.back().has<CollisionComponent>()) {
		m_objects.back().get<CollisionComponent>().addChecker([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}
	
	return m_objects.back();
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(SceneObject &obj : m_objects) {
		if(&object != &obj) {
			if(object.has<CollisionComponent>() && obj.has<CollisionComponent>()) {
				auto &collisionComponent1 = object.get<CollisionComponent>();
				auto &collisionComponent2 = obj.get<CollisionComponent>();
				
				bool collision = CollisionSystem::inCollision(object, obj);
				
				collisionComponent1.collisionActions(object, obj, collision);
				collisionComponent2.collisionActions(obj, object, collision);
			}
		}
	}
}

void Scene::removeObject(MapObject &object) {
	m_oldObjects.erase(std::remove_if(m_oldObjects.begin(), m_oldObjects.end(),
					[&](std::unique_ptr<MapObject> &it) {
						return it.get() == &object;
					}), m_oldObjects.end());
}

bool Scene::objectAtPosition(MapObject &obj, float x, float y) {
	return((floor(obj.x() / 8) == floor(x / 8)
		 || floor(obj.x() / 8) == floor(x / 8) - 1)
		&& (floor(obj.y() / 8) == floor(y / 8)
		 || floor(obj.y() / 8) == floor(y / 8) - 1));
}

MapObject *Scene::getObject(float x, float y) {
	for(auto &it : m_oldObjects) {
		if(objectAtPosition(*it, x, y)) {
			return it.get();
		}
	}
	
	return nullptr;
}

void Scene::checkCollisionsFor(MapObject *object) {
	for(auto &it : m_oldObjects) {
		MapObject *object2 = (it && it.get() != object) ? it.get() : &Player::player;
		
		if(object->inCollisionWith(*object2)) {
			object->collisionAction(*object2);
			object2->collisionAction(*object);
		}
	}
}

