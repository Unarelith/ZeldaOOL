/*
 * =====================================================================================
 *
 *       Filename:  LifetimeSystem.cpp
 *
 *    Description:  
 *
 *        Created:  26/02/2015 16:37:25
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "LifetimeComponent.hpp"
#include "LifetimeSystem.hpp"

void LifetimeSystem::process(std::deque<SceneObject> &objects) {
	for(u16 i = 0 ; i < objects.size() ; i++) {
		auto *lifetimeComponent = objects[i].getComponent<LifetimeComponent>();
		
		if(lifetimeComponent && lifetimeComponent->dead()) {
			objects.erase(objects.begin() + i);
			
			i--;
		}
	}
}

