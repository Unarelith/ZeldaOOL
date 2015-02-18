/*
 * =====================================================================================
 *
 *       Filename:  MovementComponent.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 15:10:54
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <memory>
#include <vector>

#include "Movement.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) : movement(_movement) {}
		
		float vx = 0;
		float vy = 0;
		
		float speed = 0.4f;
		
		bool isMoving = false;
		
		bool isBlocked = false;
		
		std::unique_ptr<Movement> movement;
};

#endif // MOVEMENTCOMPONENT_HPP_
