/*
 * =====================================================================================
 *
 *       Filename:  SDLLoader.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:38:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SDLLOADER_HPP_
#define SDLLOADER_HPP_

class SDLLoader {
	public:
		SDLLoader() = default;
		~SDLLoader();
		
		void load();
		
	private:
		bool m_sdlInitialized = false;
		bool m_imgInitialized = false;
		bool m_mixInitialized = false;
};

#endif // SDLLOADER_HPP_
