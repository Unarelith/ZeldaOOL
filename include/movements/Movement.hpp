/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:51:57
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "SceneObject.hpp"

class Movement {
	public:
		virtual ~Movement() = default;
		
		virtual void process(SceneObject &object) = 0;
};

#endif // MOVEMENT_HPP_
