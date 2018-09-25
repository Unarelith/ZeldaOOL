/*
 * =====================================================================================
 *
 *       Filename:  Filesystem.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 16:25:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef FILESYSTEM_HPP_
#define FILESYSTEM_HPP_

#include <string>

class Filesystem {
	public:
		static bool fileExists(const std::string &filename);
};

#endif // FILESYSTEM_HPP_
