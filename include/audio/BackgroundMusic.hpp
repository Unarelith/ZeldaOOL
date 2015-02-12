/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:46:23
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BACKGROUNDMUSIC_HPP_
#define BACKGROUNDMUSIC_HPP_

#include <memory>
#include <string>

#include "SDLHeaders.hpp"

class BackgroundMusic {
	public:
		BackgroundMusic() = default;
		BackgroundMusic(const std::string &filename);
		
		void load(const std::string &filename);
		
		void play();
		
	private:
		using Mix_MusicPtr = std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)>;
		
		Mix_MusicPtr m_music{nullptr, Mix_FreeMusic};
};

#endif // BACKGROUNDMUSIC_HPP_
