/*
 * =====================================================================================
 *
 *       Filename:  MovementComponent.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:23:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <memory>

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
