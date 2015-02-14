/*
 * =====================================================================================
 *
 *       Filename:  Direction.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 20:44:54
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
	
	None  = -1
};

#endif // DIRECTION_HPP_
