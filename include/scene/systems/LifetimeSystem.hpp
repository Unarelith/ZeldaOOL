/*
 * =====================================================================================
 *
 *       Filename:  LifetimeSystem.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:44:57
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
