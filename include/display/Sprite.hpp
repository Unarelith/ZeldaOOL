/*
 * =====================================================================================
 *
 *       Filename:  Sprite.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:38:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <initializer_list>

#include "Image.hpp"
#include "SpriteAnimation.hpp"

class Sprite : public Image {
	public:
		Sprite();
		Sprite(std::string filename, u16 frameWidth, u16 frameHeight);
		~Sprite();
		
		void load(std::string filename, u16 frameWidth, u16 frameHeight);
		
		void drawFrame(s16 x, s16 y, u16 frame);
		
		void addAnimation(std::initializer_list<u16> frames, u16 delay);
		void resetAnimation(u16 anim);
		void startAnimation(u16 anim);
		void stopAnimation(u16 anim);
		u16 animationCurrentFrame(u16 anim);
		bool animationAtEnd(u16 anim);
		void playAnimation(s16 x, s16 y, u16 anim);
		
		static bool pause;
		
	private:
		u16 m_frameWidth;
		u16 m_frameHeight;
		
		std::vector<SpriteAnimation> m_animations;
		
		u16 m_lastFrameDisplayed;
};

#endif // SPRITE_HPP_
