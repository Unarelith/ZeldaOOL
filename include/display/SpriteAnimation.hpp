/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:40:21
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATION_HPP_
#define SPRITEANIMATION_HPP_

#include <vector>

#include "Timer.hpp"

struct SpriteAnimation {
	SpriteAnimation(u16 _delay) : delay(_delay) {}
	
	u16 delay = 0;
	bool isPlaying = false;
	Timer timer;
	std::vector<u16> frames;
};

#endif // SPRITEANIMATION_HPP_
