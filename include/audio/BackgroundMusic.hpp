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

#include <string>

#include "SDLHeaders.hpp"

class BackgroundMusic {
	public:
		BackgroundMusic() = default;
		BackgroundMusic(const BackgroundMusic &) = delete;
		BackgroundMusic(BackgroundMusic &&music);
		BackgroundMusic(const std::string &filename);
		~BackgroundMusic();
		
		void load(const std::string &filename);
		
		void play();
		
	private:
		Mix_Music *m_music = nullptr;
};

#endif // BACKGROUNDMUSIC_HPP_
