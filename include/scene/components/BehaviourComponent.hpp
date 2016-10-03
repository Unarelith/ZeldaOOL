/*
 * =====================================================================================
 *
 *       Filename:  BehaviourComponent.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 12:39:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURCOMPONENT_HPP_
#define BEHAVIOURCOMPONENT_HPP_

#include "Behaviour.hpp"

class BehaviourComponent {
	public:
		BehaviourComponent(Behaviour *_behaviour) : behaviour(_behaviour) {}

		std::unique_ptr<Behaviour> behaviour;
};

#endif // BEHAVIOURCOMPONENT_HPP_
