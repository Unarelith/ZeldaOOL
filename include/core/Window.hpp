/*
 * =====================================================================================
 *
 *       Filename:  Window.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 19:50:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "SDLHeaders.hpp"
#include "Shader.hpp"
#include "Types.hpp"
#include "View.hpp"

class Window {
	public:
		Window();
		Window(const Window &) = delete;
		Window(Window &&) = delete;
		~Window();
		
		void initGL();
		
		void clear();
		void update();
		
		bool isOpen() const { return m_isOpen; }
		void close() { m_isOpen = false; }
		
	private:
		SDL_Window *m_window = nullptr;
		SDL_GLContext m_context;
		
		Shader m_shader;
		
		bool m_isOpen = false;
		
		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // WINDOW_HPP_
