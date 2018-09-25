/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 16:32:10
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
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // TILESETLOADER_HPP_
