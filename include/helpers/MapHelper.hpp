/*
 * =====================================================================================
 *
 *       Filename:  MapHelper.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 19:51:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAPHELPER_HPP_
#define MAPHELPER_HPP_

#include "Types.hpp"

namespace MapHelper {
	bool passable(s16 x, s16 y);
	bool onDoor(s16 x, s16 y);

	bool isTile(s16 x, s16 y, u16 tile);
	
	void scrollMaps(u8 direction);
}

#endif // MAPHELPER_HPP_
