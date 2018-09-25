/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.hpp
 *
 *    Description:
 *
 *        Created:  14/01/2015 00:34:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
