/*
 * =====================================================================================
 *
 *       Filename:  Sprite.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 20:41:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		Sprite() = default;
		Sprite(const std::string &filename, u16 frameWidth, u16 frameHeight);
		
		void load(const std::string &filename, u16 frameWidth, u16 frameHeight);
		
		void addAnimation(std::initializer_list<u16> frames, u16 delay);
		
		virtual void drawFrame(float x, float y, u16 frame);
		
		void resetAnimation(u16 anim, u16 frame = 0);
		void startAnimation(u16 anim);
		void stopAnimation(u16 anim);
		u16 animationCurrentFrame(u16 anim);
		bool animationAtEnd(u16 anim);
		void playAnimation(float x, float y, u16 anim);
		
		s16 currentAnimation() const { return m_currentAnimation; }
		
		static bool pause;
		
	protected:
		u16 m_frameWidth;
		u16 m_frameHeight;
		
		std::vector<SpriteAnimation> m_animations;
		
		u16 m_lastFrameDisplayed;
		
		s16 m_currentAnimation;
};

#endif // SPRITE_HPP_
