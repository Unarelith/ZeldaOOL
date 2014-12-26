/*
 * =====================================================================================
 *
 *       Filename:  SDLManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:06:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SDLMANAGER_HPP_
#define SDLMANAGER_HPP_

class SDLManager {
	public:
		static void init();
		static void free();
		
	private:
		static bool sdlInitialized;
		static bool imgInitialized;
		static bool mixInitialized;
};

#endif // SDLMANAGER_HPP_
