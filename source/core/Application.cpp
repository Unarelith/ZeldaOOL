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

Application::Application() : m_stateStack(ApplicationStateStack::getInstance()) {
	Translator::setLocale("fr_FR");

	ResourceHandler::getInstance().loadConfigFile<AudioLoader>("data/config/audio.xml");
	ResourceHandler::getInstance().loadConfigFile<TextureLoader>("data/config/textures.xml");
	ResourceHandler::getInstance().loadConfigFile<ItemLoader>("data/config/items.xml");

	GamePad::init(m_keyboardHandler);

	m_stateStack.push<MapState>();
}

void Application::handleEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				m_window.close();
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE) {
					m_window.close();
				}
				break;
			default:
				break;
		}
	}
}

void Application::run() {
	while(m_window.isOpen()) {
		handleEvents();

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			m_window.clear();

			m_stateStack.top()->draw();

			m_window.update();
		});
	}
}

