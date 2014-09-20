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

class Window {
	public:
		Window();
		~Window();
		
		void open();
		void free();
		
		void initGL();
		
		void clear();
		void update();
		
		bool isOpen() const { return m_isOpen; }
		void close() { m_isOpen = false; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		Shader defaultShader() const { return m_defaultShader; }
		
	private:
		SDL_Window *m_window;
		SDL_GLContext m_context;
		
		bool m_isOpen;
		
		u16 m_width;
		u16 m_height;
		
		Shader m_defaultShader;
};

#endif // WINDOW_HPP_
