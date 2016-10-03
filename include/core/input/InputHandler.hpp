/*
 * =====================================================================================
 *
 *       Filename:  InputHandler.hpp
 *
 *    Description:
 *
 *        Created:  12/02/2015 17:16:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

#include "GameKey.hpp"

class InputHandler {
	public:
		virtual bool isKeyPressed(GameKey key) = 0;
};

#endif // INPUTHANDLER_HPP_
