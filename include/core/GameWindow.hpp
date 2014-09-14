/*
 * =====================================================================================
 *
 *       Filename:  GameWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:01:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef GAMEWINDOW_HPP_
#define GAMEWINDOW_HPP_

#include "SDLHeaders.hpp"
#include "Types.hpp"

class GameWindow {
	public:
		GameWindow();
		~GameWindow();
		
		void clear();
		
		void update();
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		
		u16 m_width;
		u16 m_height;
};

#endif // GAMEWINDOW_HPP_
