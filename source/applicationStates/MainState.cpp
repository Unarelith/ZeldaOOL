/*
 * =====================================================================================
 *
 *       Filename:  MainState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/01/2015 11:42:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MainState.hpp"

MainState::MainState() {
}

void MainState::update() {
	m_scene.update();
}

void MainState::render() {
	m_scene.draw();
	
	m_statsBar.draw();
}

