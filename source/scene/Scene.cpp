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
#include "Scene.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

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
	
	auto *collisionComponent = m_objects.back().getComponent<CollisionComponent>();
	if(collisionComponent) {
		collisionComponent->addChecker([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}
	
	return m_objects.back();
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(SceneObject &obj : m_objects) {
		if(&object != &obj) {
			auto *collisionComponent1 = object.getComponent<CollisionComponent>();
			auto *collisionComponent2 = obj.getComponent<CollisionComponent>();
			
			if(collisionComponent1 && collisionComponent2) {
				bool collision = CollisionSystem::inCollision(object, obj);
				
				collisionComponent1->collisionActions(object, obj, collision);
				collisionComponent2->collisionActions(obj, object, collision);
			}
		}
	}
}

