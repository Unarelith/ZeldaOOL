/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:21:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationState.hpp"
#include "ApplicationStateStack.hpp"

ApplicationState::ApplicationState() {
	
}

ApplicationState::~ApplicationState() {
}

ApplicationStateStack &ApplicationState::getApplicationStateStack() {
	return ApplicationStateStack::getInstance();
}

