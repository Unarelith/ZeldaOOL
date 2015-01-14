/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/01/2015 20:27:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TEXTURELOADER_HPP_
#define TEXTURELOADER_HPP_

#include "ResourceLoader.hpp"

class TextureLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // TEXTURELOADER_HPP_
