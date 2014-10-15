/*
 * =====================================================================================
 *
 *       Filename:  CharacterState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 16:54:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHARACTERSTATE_HPP_
#define CHARACTERSTATE_HPP_

class CharacterState {
	public:
		CharacterState();
		virtual ~CharacterState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		virtual bool canStartMapTransition() { return false; }
};

#endif // CHARACTERSTATE_HPP_
