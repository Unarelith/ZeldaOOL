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

#include <stack>

#include "SDLHeaders.hpp"
#include "Types.hpp"
#include "View.hpp"

class GameWindow {
	public:
		GameWindow();
		~GameWindow();
		
		void open();
		void close();
		
		void clear();
		
		void update();
		
		SDL_Renderer *renderer() const { return m_renderer; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		View currentView() const { return m_currentView; }
		
		void setView(const View &view) { m_currentView = view; }
		void resetView() { m_currentView = m_defaultView; }
		
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		
		u16 m_width;
		u16 m_height;
		
		View m_defaultView;
		View m_currentView;
};

#endif // GAMEWINDOW_HPP_
