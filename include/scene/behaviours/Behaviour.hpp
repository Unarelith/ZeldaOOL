/*
 * =====================================================================================
 *
 *       Filename:  Behaviour.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 15:20:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOUR_HPP_
#define BEHAVIOUR_HPP_

#include "SceneObject.hpp"

class Behaviour {
	public:
		virtual void action(SceneObject &object) = 0;
};

#endif // BEHAVIOUR_HPP_
