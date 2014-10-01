/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:24
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

#include <string>

#include "SDLHeaders.hpp"
#include "Types.hpp"

class SoundEffect {
	public:
		SoundEffect();
		SoundEffect(std::string filename);
		~SoundEffect();
		
		void load(std::string filename);
		
		void play(s8 channel = -1);
		
	private:
		Mix_Chunk *m_sfx;
};

#endif // SOUNDEFFECT_HPP_
