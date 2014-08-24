/*
 * =====================================================================================
 *
 *       Filename:  TileAnimation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 14:20:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TILEANIMATION_HPP_
#define TILEANIMATION_HPP_

#include <vector>

#include "Types.hpp"

struct TileAnimation {
	TileAnimation(u16 _delay) : delay(_delay) {}
	
	std::vector<u16> frames;
	
	u16 delay;
};

#endif // TILEANIMATION_HPP_
