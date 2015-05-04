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
#include "Scene.hpp"

#include "BehaviourSystem.hpp"
#include "CollisionSystem.hpp"
#include "LifetimeSystem.hpp"
#include "MovementSystem.hpp"
#include "DrawingSystem.hpp"

SceneObject *Scene::player = nullptr;

void Scene::reset() {
	for(auto &it : m_objects) {
		BehaviourSystem::reset(it);
	}
}

void Scene::update() {
	LifetimeSystem::process(m_objects);
	
	for(auto &it : m_objects) {
		updateObject(it);
	}
	
	if(player) updateObject(*player);
	
	for(auto &it : m_oldObjects) {
		it->update();
	}
}

void Scene::updateObject(SceneObject &object) {
	MovementSystem::process(object);
	
	BehaviourSystem::process(object);
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
			CollisionSystem::checkCollision(object, obj);
		}
	}
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

