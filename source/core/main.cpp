/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:38:59
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
		std::cerr << "Fatal error " << e.what() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch(...) {
		std::cerr << "Fatal error: Unknown error." << std::endl;
	}
	
	return 0;
}

