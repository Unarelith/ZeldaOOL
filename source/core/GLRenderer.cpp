/*
 * =====================================================================================
 *
 *       Filename:  GLRenderer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 22:52:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GLRenderer.hpp"

GLRenderer::GLRenderer() {
	
}

GLRenderer::~GLRenderer() {
}

void GLRenderer::clear() {
	
}

void GLRenderer::update() {
	
}

void GLRenderer::draw(Drawable &drawable) {
	if(drawable.hasView()) drawable.useView();
	
	drawable.draw();
	
	if(drawable.hasView()) m_view.use();
}

