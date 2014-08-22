/*
 * =====================================================================================
 *
 *       Filename:  Sound.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/08/2014 02:18:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>

namespace Sound {
	void init();
	
	namespace Music {
		void init();
		
		extern sf::Music plain;
	}
	
	namespace Effect {
		void init();
		
		extern sf::SoundBuffer chestBuffer;
		extern sf::Sound chest;
	}
}

#endif // SOUND_HPP_
