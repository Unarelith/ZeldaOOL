/*
 * =====================================================================================
 *
 *       Filename:  ApplicationWindow.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:55:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONWINDOW_HPP_
#define APPLICATIONWINDOW_HPP_

#include <memory>

#include "SDLHeaders.hpp"
#include "Shader.hpp"
#include "Types.hpp"

class ApplicationWindow {
	public:
		ApplicationWindow();
		
		void initOpenGL();
		
		void clear();
		void update();
		
		bool isOpen() const { return m_isOpen; }
		void close() { m_isOpen = false; }
		
		static const u16 screenWidth = 160;
		static const u16 screenHeight = 144;
		
	private:
		using SDL_WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
		using SDL_GLContextPtr = std::unique_ptr<void, decltype(&SDL_GL_DeleteContext)>;
		
		SDL_WindowPtr m_window{nullptr, SDL_DestroyWindow};
		SDL_GLContextPtr m_context{nullptr, SDL_GL_DeleteContext};
		
		Shader m_shader;
		
		bool m_isOpen = false;
		
		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // APPLICATIONWINDOW_HPP_
