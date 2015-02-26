/*
 * =====================================================================================
 *
 *       Filename:  LifetimeSystem.hpp
 *
 *    Description:  
 *
 *        Created:  26/02/2015 16:36:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMESYSTEM_HPP_
#define LIFETIMESYSTEM_HPP_

#include <deque>

#include "SceneObject.hpp"

class LifetimeSystem {
	public:
		static void process(std::deque<SceneObject> &objects);
};

#endif // LIFETIMESYSTEM_HPP_
