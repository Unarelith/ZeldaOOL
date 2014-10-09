/*
 * =====================================================================================
 *
 *       Filename:  Object.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:59:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Object.hpp"

Object::Object(float x, float y) : Entity(x, y, 16, 16) {
}

Object::~Object() {
}

void Object::setEventAction(u8 event, std::function<void(Object *)> action) {
	m_actions[event] = action;
}

void Object::onEvent(u8 event) {
	m_actions[event](this);
}

