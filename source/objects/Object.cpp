/*
 * =====================================================================================
 *
 *       Filename:  Object.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/08/2014 01:50:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Object.hpp"

Object::Object(s16 tileX, s16 tileY) : Entity(tileX * 16, tileY * 16, 16, 16) {
}

Object::~Object() {
}

void Object::setEventAction(u8 event, std::function<void(Object *)> action) {
	m_actions[event] = action;
}

void Object::onEvent(u8 event) {
	m_actions[event](this);
}

