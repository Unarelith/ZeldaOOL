/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:47:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
