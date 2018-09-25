/*
 * =====================================================================================
 *
 *       Filename:  LifetimeController.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:45:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LifetimeComponent.hpp"
#include "LifetimeController.hpp"

void LifetimeController::update(SceneObjectList &objects) {
	for(u16 i = 0 ; i < objects.size() ; i++) {
		if(objects[i].has<LifetimeComponent>()
		&& objects[i].get<LifetimeComponent>().dead(objects[i])) {
			objects.remove(i--);
		}
	}
}

