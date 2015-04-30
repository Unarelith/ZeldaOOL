/*
 * =====================================================================================
 *
 *       Filename:  DoorLoader.hpp
 *
 *    Description:  
 *
 *        Created:  19/01/2015 21:40:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DOORLOADER_HPP_
#define DOORLOADER_HPP_

#include "ResourceLoader.hpp"

class DoorLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // DOORLOADER_HPP_
