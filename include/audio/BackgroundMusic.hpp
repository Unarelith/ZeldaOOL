/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2014 22:15:27
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

#include <SFML/Audio.hpp>

class BackgroundMusic {
	public:
		BackgroundMusic();
		BackgroundMusic(std::string filename);
		~BackgroundMusic();
		
		void open(std::string filename);
		
		void play();
		
	private:
		sf::Music m_music;
};

#endif // BACKGROUNDMUSIC_HPP_
