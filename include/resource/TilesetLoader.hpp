/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 16:32:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
