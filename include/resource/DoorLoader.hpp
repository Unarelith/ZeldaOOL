/*
 * =====================================================================================
 *
 *       Filename:  DoorLoader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/01/2015 21:40:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
