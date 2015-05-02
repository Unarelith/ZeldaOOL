/*
 * =====================================================================================
 *
 *       Filename:  Filesystem.cpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 16:27:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <fstream>

#include "Filesystem.hpp"

bool Filesystem::fileExists(const std::string &filename) {
	std::ifstream f(filename);
	if(f.good()) {
		f.close();
		return true;
	} else {
		f.close();
		return false;
	}
}

