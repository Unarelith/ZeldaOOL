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
		BehaviourComponent(Behaviour *behaviour = nullptr)
			: m_behaviour(behaviour) {}
		
		void action(SceneObject &object) {
			if(m_behaviour) {
				m_behaviour->action(object);
			}
		}
		
	private:
		std::unique_ptr<Behaviour> m_behaviour;
};

#endif // BEHAVIOURCOMPONENT_HPP_
