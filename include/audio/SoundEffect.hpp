/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:46:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SOUNDEFFECT_HPP_
#define SOUNDEFFECT_HPP_

#include <memory>
#include <string>

#include "SDLHeaders.hpp"
#include "Timer.hpp"
#include "Types.hpp"

class SoundEffect {
	public:
		SoundEffect() = default;
		SoundEffect(const std::string &filename);
		
		void load(const std::string &filename);
		
		void play(s8 channel = -1);
		
		void playDelayed(u16 delay);
		
	private:
		using Mix_ChunkPtr = std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)>;
		
		Mix_ChunkPtr m_sfx{nullptr, Mix_FreeChunk};
		
		Timer m_timer;
};

#endif // SOUNDEFFECT_HPP_
