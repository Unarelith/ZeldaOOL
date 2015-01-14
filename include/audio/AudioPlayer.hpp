/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/01/2015 00:55:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_

#include <string>

class AudioPlayer {
	public:
		static void init();
		
		static void playEffect(const std::string &name);
		static void playMusic(const std::string &name);
};

#endif // AUDIOPLAYER_HPP_
