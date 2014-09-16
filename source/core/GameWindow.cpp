/*
 * =====================================================================================
 *
 *       Filename:  GameWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:01:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "GameWindow.hpp"

GameWindow::GameWindow() {
}

GameWindow::~GameWindow() {
}

void GameWindow::open() {
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	
	info("Current display: %dx%d", current.w, current.h);
	
	m_width = current.w;
	m_height = current.h;
#else
	m_width = WINDOW_WIDTH * 3;
	m_height = WINDOW_HEIGHT * 3;
#endif
	
	m_window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
	if(!m_window) {
		error("Error while initializing window: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
	if(!m_renderer) {
		error("Renderer couldn't be created: %s\n", SDL_GetError());
		SDL_DestroyWindow(m_window);
		exit(EXIT_FAILURE);
	}
	
	SDL_RenderSetScale(m_renderer, 3, 3);
	
	m_defaultView.reset(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	m_currentView = m_defaultView;
}

void GameWindow::close() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameWindow::clear() {
	SDL_RenderClear(m_renderer);
}

void GameWindow::update() {
	SDL_RenderPresent(m_renderer);
}

