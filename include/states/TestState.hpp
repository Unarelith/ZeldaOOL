/*
 * =====================================================================================
 *
 *       Filename:  TestState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2014 21:36:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TESTSTATE_HPP_
#define TESTSTATE_HPP_

#include <SFML/Graphics/Texture.hpp>

#include "ApplicationState.hpp"
#include "Camera.hpp"
#include "World.hpp"

class TestState : public ApplicationState {
	public:
		TestState();
		~TestState();
		
		void update();
		
		void draw();
		
	private:
		Camera m_camera;
		World m_world;
		sf::Texture m_texture;
};

#endif // TESTSTATE_HPP_
