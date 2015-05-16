/*
 * =====================================================================================
 *
 *       Filename:  ItemLoader.hpp
 *
 *    Description:  
 *
 *        Created:  16/05/2015 17:07:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEMLOADER_HPP_
#define ITEMLOADER_HPP_

#include "ResourceLoader.hpp"

class ItemLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // ITEMLOADER_HPP_
