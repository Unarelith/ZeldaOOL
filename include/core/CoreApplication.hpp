/*
 * =====================================================================================
 *
 *       Filename:  CoreApplication.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2018 18:18:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COREAPPLICATION_HPP_
#define COREAPPLICATION_HPP_

#include "ApplicationStateStack.hpp"
#include "GameClock.hpp"
#include "KeyboardHandler.hpp"
#include "ResourceHandler.hpp"
#include "SDLLoader.hpp"
#include "Window.hpp"

class CoreApplication {
	public:
		CoreApplication(int argc, char **argv);

		virtual void init();

		int run();

		static const u16 screenWidth = 160;
		static const u16 screenHeight = 144;

	protected:
		ApplicationStateStack m_stateStack;

		GameClock m_clock;

		KeyboardHandler m_keyboardHandler;

		ResourceHandler m_resourceHandler;

		SDLLoader m_sdlLoader;

		Window m_window;

	private:
		void handleEvents();

		void mainLoop();
};

#endif // COREAPPLICATION_HPP_
