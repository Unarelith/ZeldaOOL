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
	
	GLUtilities::setupPerspective(80, 160 / 144, 0.1, 1000);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	m_camera.update();
	
	m_chunk.update();
}

TestState::~TestState() {
}

void TestState::update() {
	if(GamePad::getInstance().isKeyPressedOnce(GamePad::Select)) {
		ApplicationStateStack::getInstance().pop();
		Application::getInstance().window().resetGLStates();
	}
	
	m_camera.processInputs();
}

void TestState::draw() {
	glClearColor(0.196078, 0.6, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*glBegin(GL_QUADS);
		glColor3f(1, 0, 0); glVertex3f(-10, 0, 10);
		glColor3f(1, 1, 0); glVertex3f(10, 0, 10);
		glColor3f(0, 1, 1); glVertex3f(10, 0, -10);
		glColor3f(1, 0, 1); glVertex3f(-10, 0, -10);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); glVertex3f(0, 0, 0);
		glColor3f(1, 1, 1); glVertex3f(0, 5, 0);
		
		glColor3f(1, 0, 1); glVertex3f(0, 0, 0);
		glColor3f(1, 0, 1); glVertex3f(5, 0, 0);
		
		glColor3f(1, 1, 0); glVertex3f(0, 0, 0);
		glColor3f(1, 1, 0); glVertex3f(0, 0, 5);
	glEnd();*/
	
	m_chunk.draw();
}

