/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2015 23:07:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ResourceHandler.hpp"
#include "ResourceLoader.hpp"

void ResourceHandler::addType(const std::string &xmlFilename, ResourceLoader &&loader) {
	loader.load(xmlFilename, *this);
}

