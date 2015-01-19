/*
 * =====================================================================================
 *
 *       Filename:  TileAnimation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:37:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILEANIMATION_HPP_
#define TILEANIMATION_HPP_

#include <vector>

#include "Types.hpp"

struct TileAnimation {
	TileAnimation(u16 _delay) : delay(_delay) {}
	TileAnimation(TileAnimation &&tileAnimation) : frames(std::move(tileAnimation.frames)), delay(tileAnimation.delay) {}
	
	std::vector<u16> frames;
	
	u16 delay;
};

#endif // TILEANIMATION_HPP_
