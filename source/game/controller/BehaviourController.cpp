/*
 * =====================================================================================
 *
 *       Filename:  BehaviourController.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:27:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "BehaviourController.hpp"
#include "StateComponent.hpp"

void BehaviourController::reset(gk::SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().behaviour->reset(object);
	}
}

void BehaviourController::update(gk::SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().behaviour->update(object);
	}

	// FIXME
	if(object.has<StateComponent>()) {
		object.get<StateComponent>().update(object);
	}
}

