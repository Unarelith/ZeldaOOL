/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:06:18
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
		Movement() {}
		virtual ~Movement() {}
		
		virtual void doMovement(Movable &movable) = 0;
};

#endif // MOVEMENT_HPP_
