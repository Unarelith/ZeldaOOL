/*
 * =====================================================================================
 *
 *       Filename:  IconManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 13:50:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef ICONMANAGER_HPP_
#define ICONMANAGER_HPP_

#include <vector>

#include "Image.hpp"

namespace IconManager {
	void init();
	
	Image &getWeaponIconByID(u8 id);
	
	extern std::vector<Image> weapons;
}

#endif // ICONMANAGER_HPP_
