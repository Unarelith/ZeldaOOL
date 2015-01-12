/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 15:04:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include "ResourceLoader.hpp"

class MapLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // MAPLOADER_HPP_
