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
#include "MapState.hpp"
#include "ResourceHandler.hpp"

#include "AudioLoader.hpp"
#include "ItemLoader.hpp"
#include "TextureLoader.hpp"
#include "Translator.hpp"

void Application::init() {
	CoreApplication::init();

	Translator::setLocale("fr_FR");

	m_resourceHandler.loadConfigFile<AudioLoader>("data/config/audio.xml");
	m_resourceHandler.loadConfigFile<TextureLoader>("data/config/textures.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("data/config/items.xml");

	m_stateStack.push<MapState>();
}

