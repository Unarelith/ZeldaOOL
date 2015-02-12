/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:10:00
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
