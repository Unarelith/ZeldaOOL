/*
 * =====================================================================================
 *
 *       Filename:  MapEventManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:36:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAPEVENTMANAGER_HPP_
#define MAPEVENTMANAGER_HPP_

#include "Types.hpp"

namespace MapEventManager {
	void update();
	
	extern u16 lastPlayerX;
	extern u16 lastPlayerY;
}

#endif // MAPEVENTMANAGER_HPP_
