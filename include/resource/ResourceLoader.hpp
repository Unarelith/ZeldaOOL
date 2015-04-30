/*
 * =====================================================================================
 *
 *       Filename:  ResourceLoader.hpp
 *
 *    Description:  
 *
 *        Created:  12/01/2015 15:04:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
