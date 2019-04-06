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

#include <SFML/Graphics/Shader.hpp>

#include <gk/core/input/KeyboardHandler.hpp>
#include <gk/core/CoreApplication.hpp>

class Application : public gk::CoreApplication {
	public:
		Application(int argc, char **argv) : CoreApplication(argc, argv) {}

		void init() override;

	private:
		void onEvent(const sf::Event &event) override;

		sf::Shader m_shader;
		sf::View m_view;

		gk::KeyboardHandler m_keyboardHandler;
};

#endif // APPLICATION_HPP_
