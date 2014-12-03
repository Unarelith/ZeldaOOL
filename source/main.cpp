/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 18:09:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

#include "Application.hpp"
#include "Debug.hpp"
#include "Exception.hpp"

int main(int argc, char *argv[]) {
	try {
		Application &app = Application::getInstance();
		
		app.run();
	}
	catch(const Exception &err) {
		std::cerr << Debug::textColor(Debug::TextColor::Red, true) << "Fatal error " << Debug::textColor() << err.what() << std::endl;
		return 1;
	}
	catch(const std::exception &e) {
		std::cerr << Debug::textColor(Debug::TextColor::Red, true) << "Exception caught: " << Debug::textColor(0, true) << e.what() << Debug::textColor() << std::endl;
		return 1;
	}
	
	return 0;
}
