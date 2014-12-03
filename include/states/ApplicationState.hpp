/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:21:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

// Avoid cyclic inclusion
class ApplicationStateStack;

class ApplicationState {
	public:
		ApplicationState();
		virtual ~ApplicationState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		ApplicationStateStack &getApplicationStateStack();
};

#endif // APPLICATIONSTATE_HPP_
