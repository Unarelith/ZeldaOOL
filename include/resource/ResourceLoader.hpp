/*
 * =====================================================================================
 *
 *       Filename:  ResourceLoader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 15:04:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RESOURCELOADER_HPP_
#define RESOURCELOADER_HPP_

#include <string>

#include "ResourceHandler.hpp"

class ResourceLoader {
	public:
		virtual void load(const std::string &xmlFilename, ResourceHandler &handler) = 0;
};

#endif // RESOURCELOADER_HPP_
