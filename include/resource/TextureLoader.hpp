/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.hpp
 *
 *    Description:
 *
 *        Created:  14/01/2015 20:27:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
