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
#include <stack>

#include "Movement.hpp"
#include "Vector2.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) {
			movements.emplace(_movement);
		}
		
		Vector2f v{0, 0};
		
		float speed = 0.4f;
		
		bool isMoving = false;
		bool isBlocked = false;
		bool isDirectionLocked = false;
		
		std::stack<std::unique_ptr<Movement>> movements;
};

#endif // MOVEMENTCOMPONENT_HPP_
