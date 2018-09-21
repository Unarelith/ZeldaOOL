/*
 * =====================================================================================
 *
 *       Filename:  TileMapLoader.hpp
 *
 *    Description:
 *
 *        Created:  09/04/2018 01:09:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAPLOADER_HPP_
#define TILEMAPLOADER_HPP_

#include "ResourceLoader.hpp"
#include "Tileset.hpp"

class TileMapLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler) override;

		void loadMap(const std::string &name, const std::string &path, Tileset &tileset, ResourceHandler &handler);
};

#endif // TILEMAPLOADER_HPP_
