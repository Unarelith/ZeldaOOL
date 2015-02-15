/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:45:22
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Scene.hpp"

void Scene::update() {
	for(auto &it : m_objects) {
		m_movementSystem.process(it);
	}
}

void Scene::draw() {
	for(auto &it : m_objects) {
		m_drawingSystem.draw(it);
	}
}

