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
		
		void addAnimation(std::initializer_list<u16> frames, u16 delay);
		
		void setFramePosition(u16 anim, u16 animFrame, s16 x, s16 y);
		
		void drawFrame(s16 x, s16 y, u16 frame);
		void drawPositionedFrame(s16 x, s16 y, u16 anim, u16 animFrame);
		
		void resetAnimation(u16 anim);
		void startAnimation(u16 anim);
		void stopAnimation(u16 anim);
		u16 animationCurrentFrame(u16 anim);
		bool animationAtEnd(u16 anim);
		void playAnimation(s16 x, s16 y, u16 anim);
		
		static bool pause;
		
	protected:
		u16 m_frameWidth;
		u16 m_frameHeight;
		
		std::vector<SpriteAnimation> m_animations;
		
		u16 m_lastFrameDisplayed;
		
		s16 m_currentAnimation;
};

#endif // SPRITE_HPP_
