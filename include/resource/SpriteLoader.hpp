/*
 * =====================================================================================
 *
 *       Filename:  SpriteLoader.hpp
 *
 *    Description:
 *
 *        Created:  19/09/2018 20:27:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITELOADER_HPP_
#define SPRITELOADER_HPP_

#include "ResourceLoader.hpp"

class SpriteLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
		void loadSprite(const std::string &textureName, ResourceHandler &handler);
};

#endif // SPRITELOADER_HPP_
