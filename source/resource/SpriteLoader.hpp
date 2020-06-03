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

#include <gk/resource/IResourceLoader.hpp>

class SpriteLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
		void loadSprite(const std::string &textureName, gk::ResourceHandler &handler);
};

#endif // SPRITELOADER_HPP_
