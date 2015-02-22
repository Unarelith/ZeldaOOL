/*
 * =====================================================================================
 *
 *       Filename:  ApplicationWindow.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:59:20
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ApplicationWindow.hpp"
#include "Exception.hpp"
#include "OpenGL.hpp"

ApplicationWindow::ApplicationWindow() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	m_width = screenWidth * 3;
	m_height = screenHeight * 3;
	
	auto caption = "The Legend of Zelda: Oracle of Light";
	m_window.reset(SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN));
	if(!m_window) {
		throw EXCEPTION("Error while initializing window:", SDL_GetError());
	}
	
	m_context.reset(SDL_GL_CreateContext(m_window.get()));
	if(!m_context) {
		throw EXCEPTION("Error while initializing OpenGL context:", SDL_GetError());
	}
	
	initOpenGL();
	
	m_isOpen = true;
}

void ApplicationWindow::initOpenGL() {
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
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f);
	m_shader.setUniform("u_projectionMatrix", projectionMatrix);
}

void ApplicationWindow::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void ApplicationWindow::update() {
	SDL_GL_SwapWindow(m_window.get());
}

