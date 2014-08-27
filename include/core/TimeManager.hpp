/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:47:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TIMEMANAGER_HPP_
#define TIMEMANAGER_HPP_

#include <SFML/System.hpp>

#include "Types.hpp"

namespace TimeManager {
	u32 getTicks();
	
	extern sf::Clock clock;
	
	extern double dt;
};

#endif // TIMEMANAGER_HPP_
