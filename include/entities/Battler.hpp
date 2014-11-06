/*
 * =====================================================================================
 *
 *       Filename:  Battler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2014 01:10:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BATTLER_HPP_
#define BATTLER_HPP_

#include "Character.hpp"

class Battler : public Character {
	public:
		Battler();
		Battler(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		~Battler();
		
		void load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void reset();
		
		void update();
		
		void drawFrame(float x, float y, u16 frame);
		
		void addHearts(float hearts);
		void removeLife(u16 life);
		
		void hurt(u8 strength);
		virtual void hurtAction();
		
		enum BattlerType {
			TypeEnemy,
			TypePlayer
		};
		
		BattlerType battlerType() const { return m_battlerType; }
		
		s8 maxLife() const { return m_maxLife; }
		s8 life() const { return m_life; }
		
		bool hurt() const { return m_hurt; }
		
	protected:
		BattlerType m_battlerType;
		
		s8 m_maxLife;
		s8 m_life;
		
		bool m_hurt;
		
	private:
		Timer m_hurtTimer;
};

#endif // BATTLER_HPP_
