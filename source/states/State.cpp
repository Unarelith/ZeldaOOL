/*
 * =====================================================================================
 *
 *       Filename:  State.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:54:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "State.hpp"

State::State(State *parent) {
	m_parent = parent;
}

State::~State() {
}

