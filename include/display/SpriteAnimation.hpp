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

#include "Timer.hpp"

struct SpriteAnimation {
	SpriteAnimation(u16 _size, u16 *_tabAnim, u16 _delay) :
		size(_size), tabAnim(_tabAnim), delay(_delay), isPlaying(false) {}
	
	u16 size;
	u16 *tabAnim;
	u16 delay;
	Timer timer;
	bool isPlaying;
};

typedef SpriteAnimation SpriteAnimation;

#endif // SPRITEANIMATION_HPP_
