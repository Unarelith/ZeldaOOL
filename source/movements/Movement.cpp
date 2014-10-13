/*
 * =====================================================================================
 *
 *       Filename:  Movement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 00:48:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Movement.hpp"

Movement::Movement(Character *character) {
	m_character = character;
	
	m_isFinished = 0;
}

Movement::~Movement() {
}

