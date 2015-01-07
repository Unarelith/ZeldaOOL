/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 19:51:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Config.hpp"
#include "Exception.hpp"
#include "OpenGL.hpp"
#include "Window.hpp"

Window::Window() {
	m_isOpen = false;
}

Window::~Window() {
}

void Window::open() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	
	DEBUG("Current display:", current.w, "x", current.h);
	
	m_width = current.w;
	m_height = current.h;
#else
	m_width = WINDOW_WIDTH * 3;
	m_height = WINDOW_HEIGHT * 3;
#endif
	
	m_window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(!m_window) {
		throw EXCEPTION("Error while initializing window:", SDL_GetError());
	}
	
	m_context = SDL_GL_CreateContext(m_window);
	if(!m_context) {
		SDL_DestroyWindow(m_window);
		throw EXCEPTION("Error while initializing OpenGL context:", SDL_GetError());
	}
	
	initGL();
	
	m_isOpen = true;
}

void Window::free() {
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
}

void Window::initGL() {
#ifdef __MINGW32__
	if(glewInit() != GLEW_OK) {
		free();
		throw EXCEPTION("glew init failed");
	}
#endif
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	m_shader.loadFromFile("shaders/game.v.glsl", "shaders/game.f.glsl");
	
	Shader::bind(&m_shader);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	m_shader.setUniform("u_projectionMatrix", projectionMatrix);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update() {
	SDL_GL_SwapWindow(m_window);
}

