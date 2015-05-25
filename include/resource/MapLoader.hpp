/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.hpp
 *
 *    Description:  
 *
 *        Created:  12/01/2015 15:04:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include "ResourceLoader.hpp"
#include "Tileset.hpp"

class MapLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
		
		void loadMap(const std::string &name, u16 area, Vector2u16 position, Tileset &tileset, ResourceHandler &handler);
		
		static std::string makeName(u16 area, Vector2u16 position) {
			return std::to_string(area) + "-" + std::to_string(position.x) + "-" + std::to_string(position.y);
		}
};

#endif // MAPLOADER_HPP_
