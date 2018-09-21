/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 20:40:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESETLOADER_HPP_
#define TILESETLOADER_HPP_

#include "ResourceLoader.hpp"

class TilesetLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler) override;

		void loadTileset(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // TILESETLOADER_HPP_
