/*
 * =====================================================================================
 *
 *       Filename:  SceneSystem.cpp
 *
 *    Description:
 *
 *        Created:  07/05/2015 17:07:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "BattleSystem.hpp"
#include "BehaviourSystem.hpp"
#include "DrawingSystem.hpp"
#include "LifetimeSystem.hpp"
#include "SceneSystem.hpp"

#include "HealthComponent.hpp"

void SceneSystem::reset(SceneObjectList &objectList) {
	for(auto &object : objectList) resetObject(object);
}

void SceneSystem::update(SceneObjectList &objectList) {
	LifetimeSystem::process(objectList);

	for(auto &object : objectList) updateObject(object);
}

void SceneSystem::draw(SceneObjectList &objectList) {
	for(auto &object : objectList) drawObject(object);
}

void SceneSystem::resetObject(SceneObject &object) {
	BehaviourSystem::reset(object);
}

void SceneSystem::updateObject(SceneObject &object) {
	// MovementSystem::process(object);

	BattleSystem::update(object);

	BehaviourSystem::process(object);

	if(object.has<SceneObjectList>()) {
		update(object.get<SceneObjectList>());
	}
}

void SceneSystem::drawObject(SceneObject &object) {
	if(object.has<SceneObjectList>()) {
		draw(object.get<SceneObjectList>());
	}

	DrawingSystem::draw(object);
}

