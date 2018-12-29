/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 19:37:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <gk/core/input/GamePad.hpp>

#include "Application.hpp"
#include "Config.hpp"
#include "GameState.hpp"

#include "AudioLoader.hpp"
#include "ItemLoader.hpp"
#include "MapLoader.hpp"
#include "SpriteLoader.hpp"
#include "TextureLoader.hpp"
#include "TilesetLoader.hpp"
#include "Translator.hpp"

void Application::init() {
	gk::CoreApplication::init();

	gk::GamePad::init(m_keyboardHandler);

	createWindow(SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4, APP_NAME);

	initOpenGL();

	m_shader.loadFromFile("resources/shaders/game.v.glsl", "resources/shaders/game.f.glsl");
	m_renderStates.shader = &m_shader;

	m_renderStates.vertexAttributes = gk::VertexAttribute::Only2d;
	m_renderStates.projectionMatrix = glm::ortho(0.0f, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f);
	// m_renderStates.projectionMatrix = glm::ortho((float)-SCREEN_WIDTH, (float)SCREEN_WIDTH * 2, (float)SCREEN_HEIGHT * 2, (float)-SCREEN_HEIGHT);

	Translator::setLocale("fr_FR");

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");
	m_resourceHandler.loadConfigFile<TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<SpriteLoader>("resources/config/sprites.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("resources/config/items.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<MapLoader>("resources/config/maps.xml");

	m_stateStack.push<GameState>();
}

void Application::initOpenGL() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
}

void Application::onEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		m_window.close();
	}
}

