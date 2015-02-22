/*
 * =====================================================================================
 *
 *       Filename:  Direction.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 20:44:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DIRECTION_HPP_
#define DIRECTION_HPP_

#include "Types.hpp"

enum class Direction : s8 {
	Down  = 0,
	Right = 1,
	Left  = 2,
	Up    = 3,
	
	None
};

#endif // DIRECTION_HPP_
