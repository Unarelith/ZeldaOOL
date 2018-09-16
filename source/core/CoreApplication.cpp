/*
 * =====================================================================================
 *
 *       Filename:  CoreApplication.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2018 18:19:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>

#include "Config.hpp"
#include "CoreApplication.hpp"
#include "Exception.hpp"
#include "GamePad.hpp"

CoreApplication::CoreApplication(int, char **) {
}

void CoreApplication::init() {
	std::srand(std::time(nullptr));

	m_sdlLoader.load();

	m_window.open(APP_NAME, SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3);

	GamePad::init(m_keyboardHandler);

	ApplicationStateStack::setInstance(m_stateStack);

	ResourceHandler::setInstance(m_resourceHandler);
}

int CoreApplication::run() {
	try {
		init();
		mainLoop();
	}
	catch(const Exception &e) {
		std::cerr << "Fatal error " << e.what() << std::endl;
		return 1;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	catch(...) {
		std::cerr << "Fatal error: Unknown error." << std::endl;
		return 1;
	}

	return 0;
}

void CoreApplication::handleEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		if (!m_stateStack.empty())
			m_stateStack.top().onEvent(event);

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

// void CoreApplication::handleEvents() {
// 	sf::Event event;
// 	while (m_window.pollEvent(event)) {
// 		if (event.type == sf::Event::GainedFocus) {
// 			AudioPlayer::resumeMusic();
// 		}
// 		else if (event.type == sf::Event::LostFocus) {
// 			AudioPlayer::pauseMusic();
// 		}
//
// 		if (!m_stateStack.empty())
// 			m_stateStack.top().onEvent(event);
//
// 		m_keyboardHandler.updateState(event);
//
// 		if (event.type == sf::Event::Closed
// 		|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
// 			m_window.close();
// 	}
// }

#include <glm/gtc/matrix_transform.hpp>
#include "Shader.hpp"

void CoreApplication::mainLoop() {
	RenderStates states = RenderStates::Default;

	Shader shader{"shaders/game.v.glsl", "shaders/game.f.glsl"};
	states.shader = &shader;

	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f);
	states.projectionMatrix = &projectionMatrix;

	while(m_window.isOpen() && m_stateStack.size()) {
		handleEvents();

		m_clock.updateGame([&] {
			if (!m_stateStack.empty())
				m_stateStack.top().update();

			m_stateStack.clearDeletedStates();
		});

		m_clock.drawGame([&] {
			m_window.clear();

			if(!m_stateStack.empty())
				m_window.draw(m_stateStack.top(), states);

			m_window.display();
		});
	}
}

