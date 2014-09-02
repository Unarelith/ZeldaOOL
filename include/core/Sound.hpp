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

class BackgroundMusic {
	public:
		BackgroundMusic() {}
		BackgroundMusic(std::string filename) {
			open(filename);
		}
		~BackgroundMusic() {}
		
		void open(std::string filename) {
			m_music.openFromFile(filename);
			m_music.setLoop(true);
		}
		
		void play() {
			m_music.play();
		}
		
	private:
		sf::Music m_music;
};

class SoundEffect {
	public:
		SoundEffect() {}
		SoundEffect(std::string filename) {
			load(filename);
		}
		~SoundEffect() {}
		
		void load(std::string filename) {
			m_buffer.loadFromFile(filename);
			m_sfx.setBuffer(m_buffer);
		}
		
		void play() {
			m_sfx.play();
		}
		
	private:
		sf::SoundBuffer m_buffer;
		sf::Sound m_sfx;
};

namespace Sound {
	void init();
	
	namespace Music {
		void init();
		
		extern BackgroundMusic plain;
	}
	
	namespace Effect {
		void init();
		
		extern SoundEffect chest;
		
		extern SoundEffect swordCharge;
		extern SoundEffect swordSlash1;
		extern SoundEffect swordSpin;
		extern SoundEffect swordTap;
	}
}

#endif // SOUND_HPP_
