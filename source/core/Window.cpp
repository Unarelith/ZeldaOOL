/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 19:51:04
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "OpenGL.hpp"
#include "Exception.hpp"
#include "Window.hpp"

void Window::open() {
	const char *caption = "The Legend of Zelda: Oracle of Light";
	open(caption, Application::screenWidth * 3, Application::screenHeight * 3);
}

void Window::open(const std::string &caption, u16 width, u16 height) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	m_window.reset(SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN));
	if(!m_window) {
		throw EXCEPTION("Window initialization failed:", SDL_GetError());
	}

	m_context.reset(SDL_GL_CreateContext(m_window.get()));
	if(!m_context) {
		throw EXCEPTION("OpenGL context creation failed:", SDL_GetError());
	}

	m_width = width;
	m_height = height;

	m_isOpen = true;
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::display() {
	SDL_GL_SwapWindow(m_window.get());
}

void Window::setVerticalSyncEnabled(bool enabled) {
	if(SDL_GL_SetSwapInterval(enabled) < 0) {
		DEBUG("Warning: Can't enable VSync");
	}
}

