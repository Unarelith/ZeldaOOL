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

#include "Image.hpp"
#include "SpriteAnimation.hpp"

class Sprite : public Image {
	public:
		Sprite() = default;
		Sprite(const std::string &filename, u16 frameWidth, u16 frameHeight);
		
		void load(const std::string &filename, u16 frameWidth, u16 frameHeight);
		
		void addAnimation(std::vector<u16> frames, u16 delay);
		void addAnimation(std::vector<u16> frames, std::vector<std::pair<s16, s16>> positions, u16 delay);
		
		void drawFrame(float x, float y, u16 frame);
		
		void playAnimation(float x, float y, u16 anim);
		
		u16 frameWidth() const { return m_frameWidth; }
		u16 frameHeight() const { return m_frameHeight; }
		
		SpriteAnimation &getAnimation(u16 anim) { return m_animations[anim]; }
		SpriteAnimation &currentAnimation() { return m_animations[m_currentAnimation]; }
		
		static bool pause;
		
	private:
		u16 m_frameWidth = 0;
		u16 m_frameHeight = 0;
		
		std::vector<SpriteAnimation> m_animations;
		
		u16 m_currentAnimation = 0;
};

#endif // SPRITE_HPP_
