/*
 * =====================================================================================
 *
 *       Filename:  GamePad.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:22:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <memory>

class InputHandler;

class GamePad {
	public:
		GamePad();
		~GamePad();
		
		void update();
		
		enum Key {
			Left,
			Right,
			Up,
			Down,
			
			A,
			B,
			
			Start,
			Select
		};
		
		bool isKeyPressed(Key key);
		
		static GamePad &getInstance() {
			static GamePad instance;
			return instance;
		}
		
	private:
		std::unique_ptr<InputHandler> m_inputHandler;
};

#endif // GAMEPAD_HPP_
