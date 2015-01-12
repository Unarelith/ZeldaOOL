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
		
		static std::string makeName(u16 area, u16 x, u16 y) {
			return std::to_string(area) + "-" + std::to_string(x) + "-" + std::to_string(y);
		}
};

#endif // MAPLOADER_HPP_
