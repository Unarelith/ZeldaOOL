/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SOUNDEFFECT_HPP_
#define SOUNDEFFECT_HPP_

#include <memory>
#include <string>

#include "SDLHeaders.hpp"
#include "Types.hpp"

class SoundEffect {
	public:
		SoundEffect() = default;
		SoundEffect(const SoundEffect &) = delete;
		SoundEffect(SoundEffect &&soundEffect) = default;
		SoundEffect(const std::string &filename);
		
		void load(const std::string &filename);
		
		void play(s8 channel = -1);
		
		static void play(const std::string &resourceName);
		
	private:
		using Mix_ChunkPtr = std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)>;
		
		Mix_ChunkPtr m_sfx{nullptr, Mix_FreeChunk};
};

#endif // SOUNDEFFECT_HPP_
