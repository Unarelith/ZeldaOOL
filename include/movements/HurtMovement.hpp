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

#include "Character.hpp"

class HurtMovement {
	public:
		HurtMovement(Character *character, float speed = 0.4f);
		
		void reset();
		
		void update();
		
		bool isFinished() const { return m_isFinished; }
		
	protected:
		Character *m_character = nullptr;
		
		bool m_isFinished = false;
		
		float m_speed = 0;
		
		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
