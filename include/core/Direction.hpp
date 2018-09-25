/*
 * =====================================================================================
 *
 *       Filename:  Direction.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:26:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DIRECTION_HPP_
#define DIRECTION_HPP_

#include "IntTypes.hpp"

enum class Direction : s8 {
	None  = -1,

	Down  = 0,
	Right = 1,
	Left  = 2,
	Up    = 3
};

#endif // DIRECTION_HPP_
