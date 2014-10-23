/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 00:51:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef HURTMOVEMENT_HPP_
#define HURTMOVEMENT_HPP_

#include "Movement.hpp"

class HurtMovement : public Movement {
	public:
		HurtMovement(Character *character, float speed = 0.4f);
		~HurtMovement();
		
		void reset();
		
		void update();
		
	private:
		float m_speed;
		
		float m_movementCounter;
};

#endif // HURTMOVEMENT_HPP_
