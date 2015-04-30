/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Created:  13/10/2014 00:48:24
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

class Movable;

class Movement {
	public:
		virtual void reset(Movable &) {}
		
		virtual void doMovement(Movable &movable) = 0;
};

#endif // MOVEMENT_HPP_
