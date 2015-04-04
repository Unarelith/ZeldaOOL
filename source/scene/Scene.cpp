/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:45:22
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "Scene.hpp"

#include "CollisionSystem.hpp"
#include "DrawingSystem.hpp"
#include "LifetimeSystem.hpp"
#include "MovementSystem.hpp"

SceneObject *Scene::player = nullptr;

void Scene::update() {
	LifetimeSystem::process(m_objects);
	
	for(SceneObject &object : m_objects) {
		MovementSystem::process(object);
	}
	
	if(player) MovementSystem::process(*player);
}

void Scene::draw() {
	for(SceneObject &object : m_objects) {
		DrawingSystem::draw(object);
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

