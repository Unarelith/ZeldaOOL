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

void Application::init() {
	gk::CoreApplication::init();

	createWindow(sf::VideoMode(SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4), APP_NAME, sf::Style::Close);

	m_shader.loadFromFile("resources/shaders/game.v.glsl", sf::Shader::Vertex);
	m_shader.loadFromFile("resources/shaders/game.f.glsl", sf::Shader::Fragment);

	m_view.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_window.setView(m_view);

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
		m_isRunning = false;
	}
}

