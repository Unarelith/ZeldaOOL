/*
 * =====================================================================================
 *
 *       Filename:  KeyboardMovement.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 02:00:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
