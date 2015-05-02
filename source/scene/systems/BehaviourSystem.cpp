/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 15:27:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourSystem.hpp"

#include "BehaviourComponent.hpp"

void BehaviourSystem::process(SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().behaviour->action(object);
	}
}

