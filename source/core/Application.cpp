/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 19:37:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.hpp"
#include "GamePad.hpp"
#include "MapState.hpp"
#include "ResourceHandler.hpp"

#include "AudioLoader.hpp"
#include "ItemLoader.hpp"
#include "TextureLoader.hpp"
#include "Translator.hpp"

void Application::init() {
	CoreApplication::init();

	Translator::setLocale("fr_FR");

	initOpenGL();

	m_resourceHandler.loadConfigFile<AudioLoader>("data/config/audio.xml");
	m_resourceHandler.loadConfigFile<TextureLoader>("data/config/textures.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("data/config/items.xml");

	m_stateStack.push<MapState>();
}

void Application::initOpenGL() {
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

