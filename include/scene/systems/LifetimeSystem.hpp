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

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class LifetimeSystem {
	public:
		static void process(SceneObjectList &objects);
};

#endif // LIFETIMESYSTEM_HPP_
