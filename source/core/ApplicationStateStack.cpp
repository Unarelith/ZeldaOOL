/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:09:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "MapState.hpp"

ApplicationStateStack::ApplicationStateStack() {
	push(new MapState);
}

ApplicationStateStack::~ApplicationStateStack() {
}

ApplicationStateStack &ApplicationStateStack::getInstance() {
	static ApplicationStateStack instance;
	return instance;
}

