/*
 * =====================================================================================
 *
 *       Filename:  ItemLoader.hpp
 *
 *    Description:
 *
 *        Created:  16/05/2015 17:07:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEMLOADER_HPP_
#define ITEMLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class ItemLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // ITEMLOADER_HPP_
