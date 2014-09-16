/*
 * =====================================================================================
 *
 *       Filename:  View.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/09/2014 21:44:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "SDLHeaders.hpp"
#include "View.hpp"

View::View() {
}

View::~View() {
}

void View::reset(const FloatRect &rect) {
	m_rect = rect;
}

void View::move(float offsetX, float offsetY) {
	m_rect.x -= offsetX;
	m_rect.y -= offsetY;
}

