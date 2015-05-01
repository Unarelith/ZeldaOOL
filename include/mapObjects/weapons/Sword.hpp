/*
 * =====================================================================================
 *
 *       Filename:  Sword.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:26:08
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORD_HPP_
#define SWORD_HPP_

#include "Weapon.hpp"

class Sword : public Weapon {
	public:
		Sword();
		
		void reset();
		
		void update();
		void updatePosition();
		
		void draw();
		
		void collisionAction(MapObject &object);
		
		void updateOwnerNextState() override;
		
		enum State {
			Swinging,
			Loading,
			Tapping,
			SpinAttack
		};
		
		State state() const { return m_state; }
		
		s8 spinFrameCounter() const { return m_spinFrameCounter; }
		
	private:
		State m_state = State::Swinging;
		
		Timer m_loadingTimer;
		bool m_loaded = false;
		
		Timer m_spinTimer;
		s8 m_spinCurrentFrame = 0;
		s8 m_spinFrameCounter = 0;
		
		bool m_keyReleased = false;
};

#endif // SWORD_HPP_
