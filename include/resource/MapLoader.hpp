/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.hpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 15:04:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>
#include "Tileset.hpp"

class MapLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;

		void loadMap(const std::string &name, u16 area, u16 x, u16 y, Tileset &tileset, gk::ResourceHandler &handler);

		static std::string makeName(u16 area, u16 x, u16 y) {
			return std::to_string(area) + "-" + std::to_string(x) + "-" + std::to_string(y);
		}
};

#endif // MAPLOADER_HPP_
