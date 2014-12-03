/*
 * =====================================================================================
 *
 *       Filename:  TileAnimation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 14:34:56
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
	
	std::vector<u16> frames;
	
	u16 delay;
};

#endif // TILEANIMATION_HPP_
