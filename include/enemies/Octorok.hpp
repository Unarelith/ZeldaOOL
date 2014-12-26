/*
 * =====================================================================================
 *
 *       Filename:  Octorok.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 21:39:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef OCTOROK_HPP_
#define OCTOROK_HPP_

#include "Enemy.hpp"
#include "HurtMovement.hpp"

class Octorok : public Enemy {
	public:
		Octorok();
		Octorok(u16 x, u16 y, u8 direction);
		~Octorok();
		
		void load(u16 x, u16 y, u8 direction);
		
		void reset();
		void resetMovement();
		
		void update();
		
		void draw();
		
		void mapCollisionAction(float vx, float vy);
		
		enum State {
			Standing,
			Moving,
			Hurt
		};
		
		void hurtAction();
		
	private:
		State m_state;
		
		Timer m_timer;
		
		float m_movementCounter;
		
		u16 m_randomMinTimeToWait;
		u16 m_randomMaxMovement;
		
		HurtMovement *m_hurtMovement;
};

#endif // OCTOROK_HPP_
