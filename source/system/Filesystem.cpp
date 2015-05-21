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
#include <sys/types.h>
#include <sys/stat.h>

#include "Filesystem.hpp"

bool Filesystem::fileExists(const std::string &filename) {
	struct stat info;
	
	return !stat(filename.c_str(), &info);
}

