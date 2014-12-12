/*
 * =====================================================================================
 *
 *       Filename:  TestState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2014 21:37:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "GLUtilities.hpp"
#include "TestState.hpp"

TestState::TestState() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // Turn on hidden face tagging
	//glCullFace(GL_BACK); // Hidden faces = back faces
	//glFrontFace(GL_CCW); // Front face = Trigo way
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	GLUtilities::setupPerspective(80, 1, 0.1, 1000);
	
	// Required on OS X!
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	m_camera.update();
	
	m_texture.loadFromFile("graphics/tilesets/plain.png");
}

TestState::~TestState() {
}

void TestState::update() {
	printOpenGLErrors();
	
	if(GamePad::getInstance().isKeyPressedOnce(GamePad::Select)) {
		ApplicationStateStack::getInstance().pop();
		Application::getInstance().window().popGLStates();
	}
	
	m_camera.processInputs();
}

void TestState::draw() {
	glClearColor(0.196078, 0.6, 0.8, 1.0); // Skyblue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*sf::Texture::bind(&m_texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(-100, 0, 100);
		glTexCoord2f(1, 1); glVertex3f(100, 0, 100);
		glTexCoord2f(1, 0); glVertex3f(100, 0, -100);
		glTexCoord2f(0, 0); glVertex3f(-100, 0, -100);
	glEnd();
	sf::Texture::bind(nullptr);*/
	
	/*glBegin(GL_LINES);
		glColor3f(1, 1, 1); glVertex3f(0, 0, 0);
		glColor3f(1, 1, 1); glVertex3f(0, 5, 0);
		
		glColor3f(1, 0, 1); glVertex3f(0, 0, 0);
		glColor3f(1, 0, 1); glVertex3f(5, 0, 0);
		
		glColor3f(1, 1, 0); glVertex3f(0, 0, 0);
		glColor3f(1, 1, 0); glVertex3f(0, 0, 5);
	glEnd();*/
	
	m_world.draw();
}

