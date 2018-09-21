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
#include "Application.hpp"
#include "GamePad.hpp"
#include "GameState.hpp"
#include "ResourceHandler.hpp"

#include "AudioLoader.hpp"
#include "ItemLoader.hpp"
#include "MapLoader.hpp"
#include "SpriteLoader.hpp"
#include "TextureLoader.hpp"
#include "TilesetLoader.hpp"
#include "Translator.hpp"

void Application::init() {
	CoreApplication::init();

	Translator::setLocale("fr_FR");

	initOpenGL();

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");
	m_resourceHandler.loadConfigFile<TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<SpriteLoader>("resources/config/sprites.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("resources/config/items.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<MapLoader>("resources/config/maps.xml");

	m_stateStack.push<GameState>();
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
}

