/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 15:26:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURSYSTEM_HPP_
#define BEHAVIOURSYSTEM_HPP_

#include "SceneObject.hpp"

class BehaviourSystem {
	public:
		static void process(SceneObject &object);
};

#endif // BEHAVIOURSYSTEM_HPP_
