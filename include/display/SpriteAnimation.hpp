/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 20:40:52
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
