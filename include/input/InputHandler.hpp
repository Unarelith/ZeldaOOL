/*
 * =====================================================================================
 *
 *       Filename:  InputHandler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:25:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

#include "GamePad.hpp"

class InputHandler {
	public:
		InputHandler();
		~InputHandler();
		
		virtual void update() = 0;
		
		virtual bool isKeyPressed(GamePad::Key key) = 0;
};

#endif // INPUTHANDLER_HPP_
