/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:45:22
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "DrawingSystem.hpp"
#include "MovementComponent.hpp"
#include "MovementSystem.hpp"
#include "Scene.hpp"

void Scene::update() {
	for(auto &it : m_objects) {
		MovementSystem::process(it);
	}
}

void Scene::draw() {
	for(auto &it : m_objects) {
		DrawingSystem::draw(it);
	}
}

SceneObject &Scene::addObject(SceneObject &&object) {
	m_objects.push_back(std::move(object));
	
	CollisionComponent *collisionComponent = m_objects.back().getComponent<CollisionComponent>();
	if(collisionComponent) {
		collisionComponent->checkers.push_back([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}
	
	return m_objects.back();
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(auto &it : m_objects) {
		if(&object != &it) {
			CollisionComponent *collisionComponent1 = object.getComponent<CollisionComponent>();
			CollisionComponent *collisionComponent2 = it.getComponent<CollisionComponent>();
			
			if(collisionComponent1 && collisionComponent2) {
				// Collision actions goes here
			}
		}
	}
}

