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
#include "Debug.hpp"
#include "Exception.hpp"
#include "SDLLoader.hpp"

int main(int, char *[]) {
	SDLLoader sdlLoader;
	
	try {
		sdlLoader.load();
		
		Application app;
		
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
	catch(...) {
		std::cerr << "Fatal error: Unknown error." << std::endl;
		return 1;
	}
	
	return 0;
}

