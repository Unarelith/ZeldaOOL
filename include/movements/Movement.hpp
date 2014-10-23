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

#include "Character.hpp"

class Movement {
	public:
		Movement(Character *character);
		virtual ~Movement();
		
		virtual void reset() = 0;
		
		virtual void update() = 0;
		
		bool isFinished() const { return m_isFinished; }
		
	protected:
		Character *m_character;
		
		bool m_isFinished;
};

#endif // MOVEMENT_HPP_
