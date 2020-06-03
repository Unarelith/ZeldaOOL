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

// #include <gk/gl/Vertex.hpp>

void Application::init() {
	gk::CoreApplication::init();

	// m_window.addVertexAttribute(gk::VertexAttribute::Coord3d, "coord3d", 4, GL_FLOAT, GL_FALSE, sizeof(gk::Vertex), reinterpret_cast<GLvoid *>(offsetof(gk::Vertex, coord3d)));
	// m_window.addVertexAttribute(gk::VertexAttribute::TexCoord, "texCoord", 2, GL_FLOAT, GL_FALSE, sizeof(gk::Vertex), reinterpret_cast<GLvoid *>(offsetof(gk::Vertex, texCoord)));
	// m_window.addVertexAttribute(VertexAttribute::Color, "color", 4, GL_FLOAT, GL_FALSE, sizeof(gk::Vertex), reinterpret_cast<GLvoid *>(offsetof(gk::Vertex, color)));

	createWindow(sf::VideoMode{SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4}, APP_NAME, sf::Style::Titlebar | sf::Style::Close);

	m_window.disableView();

	m_shader.loadFromFile("resources/shaders/game.v.glsl", "resources/shaders/game.f.glsl");
	m_renderStates.shader = &m_shader;

	m_renderStates.projectionMatrix = glm::ortho(0.0f, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f);
	// m_renderStates.projectionMatrix = glm::ortho((float)-SCREEN_WIDTH, (float)SCREEN_WIDTH * 2, (float)SCREEN_HEIGHT * 2, (float)-SCREEN_HEIGHT);

	m_keyboardHandler.loadKeysFromFile("resources/config/keys.xml");
	gk::GamePad::init(m_keyboardHandler);

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");
	m_resourceHandler.loadConfigFile<TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<SpriteLoader>("resources/config/sprites.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("resources/config/items.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<MapLoader>("resources/config/maps.xml");

	m_stateStack.push<GameState>();
}

void Application::onEvent(const sf::Event &event) {
	gk::CoreApplication::onEvent(event);

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		m_window.window().close();
	}
}

