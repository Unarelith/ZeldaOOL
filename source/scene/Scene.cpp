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
#include "CollisionSystem.hpp"
#include "DrawingSystem.hpp"
#include "MovementComponent.hpp"
#include "MovementSystem.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"

SceneObject *Scene::player = nullptr;

void Scene::update() {
	for(auto &it : m_objects) {
		MovementSystem::process(it);
	}
	
	if(player) MovementSystem::process(*player);
}

void Scene::draw() {
	for(auto &it : m_objects) {
		DrawingSystem::draw(it);
	}
	
	if(player) DrawingSystem::draw(*player);
}

SceneObject &Scene::addObject(SceneObject &&object) {
	m_objects.push_front(std::move(object));
	
	auto *collisionComponent = m_objects.back().getComponent<CollisionComponent>();
	if(collisionComponent) {
		collisionComponent->addChecker([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}
	
	return m_objects.back();
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(auto &it : m_objects) {
		if(&object != &it) {
			auto *collisionComponent1 = object.getComponent<CollisionComponent>();
			auto *collisionComponent2 = it.getComponent<CollisionComponent>();
			
			if(collisionComponent1 && collisionComponent2) {
				bool collision = CollisionSystem::inCollision(object, it);
				
				collisionComponent1->collisionActions(object, it, collision);
				collisionComponent2->collisionActions(it, object, collision);
			}
		}
	}
}

