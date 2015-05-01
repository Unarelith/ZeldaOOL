/*
 * =====================================================================================
 *
 *       Filename:  Battler.hpp
 *
 *    Description:  
 *
 *        Created:  11/10/2014 01:10:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLER_HPP_
#define BATTLER_HPP_

#include "Character.hpp"

class Battler : public Character {
	public:
		Battler() = default;
		Battler(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		virtual void reset(Map &) override;
		
		virtual void update() override;
		
		void drawFrame(float x, float y, u16 frame);// override;
		
		void addHearts(float hearts);
		void removeLife(u16 life);
		
		void hurt(u8 strength, s16 vx, s16 vy);
		virtual void hurtAction(s16 vx, s16 vy);
		
		s8 maxLife() const { return m_maxLife; }
		s8 life() const { return m_life; }
		
		bool hurt() const { return m_hurt; }
		
	protected:
		s8 m_maxLife = 1;
		s8 m_life = 1;
		
		bool m_hurt = false;
		
	private:
		Timer m_hurtTimer;
};

#endif // BATTLER_HPP_
