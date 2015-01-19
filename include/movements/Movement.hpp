/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 00:48:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
