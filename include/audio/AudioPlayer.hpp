/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:46:46
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_

#include <string>

#include "Types.hpp"

class AudioPlayer {
	public:
		static void playMusic(const std::string &resourceName);
		
		static void playEffect(const std::string &resourceName, s8 channel = -1);
		
		static void pauseMusic();
		static void resumeMusic();
		
		static bool isMusicPaused();
		static bool isMusicPlaying();
};

#endif // AUDIOPLAYER_HPP_
