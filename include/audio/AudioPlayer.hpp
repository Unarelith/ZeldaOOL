/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.hpp
 *
 *    Description:
 *
 *        Created:  28/04/2015 21:51:27
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_

#include <string>

#include "IntTypes.hpp"

class AudioPlayer {
	public:
		static void playMusic(const std::string &resourceName);

		static void playEffect(const std::string &resourceName, s8 channel = -1);
		static void repeatEffect(const std::string &resourceName, u8 delay = 0);

		static void pauseMusic();
		static void resumeMusic();

		static bool isMusicPaused();
		static bool isMusicPlaying();
};

#endif // AUDIOPLAYER_HPP_
