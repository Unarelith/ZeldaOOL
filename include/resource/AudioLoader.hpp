/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:47:16
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef AUDIOLOADER_HPP_
#define AUDIOLOADER_HPP_

#include "ResourceLoader.hpp"

class AudioLoader : public ResourceLoader {
	public:
		void load(const std::string &xmlFilename, ResourceHandler &handler);
};

#endif // AUDIOLOADER_HPP_
