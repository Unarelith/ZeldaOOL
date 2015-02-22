/*
 * =====================================================================================
 *
 *       Filename:  TileAnimation.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:00:06
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
	
	u16 delay = 0;
};

#endif // TILEANIMATION_HPP_
