/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
		BackgroundMusic(const BackgroundMusic &) = delete;
		BackgroundMusic(BackgroundMusic &&music) = default;
		BackgroundMusic(const std::string &filename);
		
		void load(const std::string &filename);
		
		void play();
		
		static void play(const std::string &resourceName);
		
	private:
		using Mix_MusicPtr = std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)>;
		
		Mix_MusicPtr m_music{nullptr, Mix_FreeMusic};
};

#endif // BACKGROUNDMUSIC_HPP_
