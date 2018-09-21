/*
 * =====================================================================================
 *
 *       Filename:  BehaviourController.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:27:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "BehaviourController.hpp"

void BehaviourController::reset(SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().behaviour->reset(object);
	}
}

void BehaviourController::update(SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().behaviour->action(object);
	}
}

