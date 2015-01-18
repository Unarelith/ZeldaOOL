/*
 * =====================================================================================
 *
 *       Filename:  KeyboardMovement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 02:00:33
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
		void doMovement(Movable &movable) override;
};

#endif // KEYBOARDMOVEMENT_HPP_
