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

int main(int argc, char *argv[]) {
	try {
		Application &app = Application::getInstance();
		
		app.run();
	}
	catch(const std::string &err) {
		std::cerr << "Fatal error: " << err << std::endl;
		return 1;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
