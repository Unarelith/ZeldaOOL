/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Created:  14/09/2014 23:45:15
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <iostream>

#include "Application.hpp"
#include "Exception.hpp"
#include "SDLLoader.hpp"

int main(int, char *[]) {
	SDLLoader sdlLoader;
	
	try {
		sdlLoader.load();
		
		Application app;
		
		app.run();
	}
	catch(const Exception &e) {
		std::cerr << "[" << __TIME__ << "] " << "Fatal error " << e.what() << std::endl;
		return 1;
	}
	catch(const std::exception &e) {
		std::cerr << "[" << __TIME__ << "] " << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	catch(...) {
		std::cerr << "[" << __TIME__ << "] " << "Fatal error: Unknown error." << std::endl;
		return 1;
	}
	
	return 0;
}

