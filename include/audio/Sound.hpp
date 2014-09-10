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

#include "BackgroundMusic.hpp"
#include "SoundEffect.hpp"

namespace Sound {
	void init();
	
	namespace Music {
		void init();
		
		extern BackgroundMusic plain;
	}
	
	namespace Effect {
		void init();
		
		extern SoundEffect chest;
		
		extern SoundEffect grassDestroy;
		
		extern SoundEffect swordCharge;
		extern SoundEffect swordSlash1;
		extern SoundEffect swordSpin;
		extern SoundEffect swordTap;
	}
}

#endif // SOUND_HPP_
