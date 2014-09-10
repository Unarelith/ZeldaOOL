/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2014 22:16:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SOUNDEFFECT_HPP_
#define SOUNDEFFECT_HPP_

#include <SFML/Audio.hpp>

class SoundEffect {
	public:
		SoundEffect();
		SoundEffect(std::string filename);
		~SoundEffect();
		
		void load(std::string filename);
		
		void play();
		
	private:
		sf::SoundBuffer m_buffer;
		sf::Sound m_sfx;
};

#endif // SOUNDEFFECT_HPP_
