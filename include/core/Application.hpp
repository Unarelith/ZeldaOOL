/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 19:37:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <gk/core/CoreApplication.hpp>
#include <gk/gl/Shader.hpp>

#include "KeyboardHandler.hpp"

class Application : public gk::CoreApplication {
	public:
		Application(int argc, char **argv) : CoreApplication(argc, argv) {}

		void init() override;

		void initOpenGL();

	private:
		void onEvent(const SDL_Event &event) override;

		KeyboardHandler m_keyboardHandler;

		gk::Shader m_shader;
};

#endif // APPLICATION_HPP_
