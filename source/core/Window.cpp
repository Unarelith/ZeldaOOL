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
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.hpp"
#include "Exception.hpp"
#include "OpenGL.hpp"
#include "Window.hpp"

Window::Window() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	m_width = Application::screenWidth * 3;
	m_height = Application::screenHeight * 3;
	
	auto caption = "The Legend of Zelda: Oracle of Light";
	m_window.reset(SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN));
	if(!m_window) {
		throw EXCEPTION("Error while initializing window:", SDL_GetError());
	}
	
	m_context.reset(SDL_GL_CreateContext(m_window.get()));
	if(!m_context) {
		throw EXCEPTION("Error while initializing OpenGL context:", SDL_GetError());
	}
	
	initGL();
	
	m_isOpen = true;
}

void Window::initGL() {
#ifdef __MINGW32__
	if(glewInit() != GLEW_OK) {
		throw EXCEPTION("glew init failed");
	}
#endif
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	m_shader.loadFromFile("shaders/game.v.glsl", "shaders/game.f.glsl");
	
	Shader::bind(&m_shader);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)Application::screenWidth, (float)Application::screenHeight, 0.0f);
	m_shader.setUniform("u_projectionMatrix", projectionMatrix);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update() {
	SDL_GL_SwapWindow(m_window.get());
}

