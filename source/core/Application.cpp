/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:54:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "AudioLoader.hpp"
#include "GamePad.hpp"
#include "EventHandler.hpp"
#include "MapLoader.hpp"
#include "ResourceHandler.hpp"
#include "TestState.hpp"
#include "TextureLoader.hpp"
#include "TilesetLoader.hpp"

Application::Application() : m_stateStack(ApplicationStateStack::getInstance()) {
	ResourceHandler::getInstance().addType<AudioLoader>("data/config/audio.xml");
	ResourceHandler::getInstance().addType<TextureLoader>("data/config/textures.xml");
	ResourceHandler::getInstance().addType<TilesetLoader>("data/config/tilesets.xml");
	ResourceHandler::getInstance().addType<MapLoader>("data/config/maps.xml");
	
	GamePad::init(m_keyboardHandler);
	
	m_stateStack.push<TestState>();
}

void Application::run() {
	while(m_window.isOpen() && m_stateStack.size() > 0) {
		EventHandler::processSDLEvents(m_window);
		
		m_clock.updateGame([&] {
			if(m_stateStack.size() > 0) m_stateStack.top()->update();
		});
		
		m_clock.drawGame([&] {
			m_window.clear();
			
			if(m_stateStack.size() > 0) m_stateStack.top()->draw();
			
			m_window.update();
		});
	}
}

