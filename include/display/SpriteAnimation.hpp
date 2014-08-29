/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:36:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATION_HPP_
#define SPRITEANIMATION_HPP_

#include <vector>

#include "Timer.hpp"

struct SpriteAnimation {
	SpriteAnimation(u16 _delay) :
		delay(_delay), isPlaying(false) {}
	
	u16 delay;
	bool isPlaying;
	Timer timer;
	std::vector<u16> frames;
};

#endif // SPRITEANIMATION_HPP_
