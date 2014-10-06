/*
 * =====================================================================================
 *
 *       Filename:  Sound.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:11
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
		
		extern SoundEffect dialogContinue;
		
		extern SoundEffect grassDestroy;
		
		extern SoundEffect itemNew;
		
		extern SoundEffect mapStairs;
		
		extern SoundEffect menuClose;
		extern SoundEffect menuCursor;
		extern SoundEffect menuOpen;
		extern SoundEffect menuSelect;
		
		extern SoundEffect swordCharge;
		extern SoundEffect swordSlash1;
		extern SoundEffect swordSpin;
		extern SoundEffect swordTap;
		
		extern SoundEffect textLetter;
	}
}

#endif // SOUND_HPP_
