/*
 * =====================================================================================
 *
 *       Filename:  KeyboardMovement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:09:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef KEYBOARDMOVEMENT_HPP_
#define KEYBOARDMOVEMENT_HPP_

#include "Movement.hpp"

class KeyboardMovement : public Movement {
	public:
		KeyboardMovement();
		~KeyboardMovement();
		
		void doMovement(Movable &movable);
};

#endif // KEYBOARDMOVEMENT_HPP_
