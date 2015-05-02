/*
 * =====================================================================================
 *
 *       Filename:  SwordBehaviour.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 17:44:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORDBEHAVIOUR_HPP_
#define SWORDBEHAVIOUR_HPP_

#include "Behaviour.hpp"
#include "Timer.hpp"

class SwordBehaviour : public Behaviour {
	public:
		SwordBehaviour() { m_loadingTimer.start(); }
		
		void action(SceneObject &object) override;
		
		void updateSprite(SceneObject &object);
		
	private:
		enum class State {
			Swinging,
			Loading,
			SpinAttack
		};
		
		State m_state = State::Swinging;
		
		bool m_keyReleased = false;
		
		bool m_isLoaded = false;
		Timer m_loadingTimer;
		
		u16 m_spinCurrentFrame = 0;
		u16 m_spinFrameCounter = 0;
		Timer m_spinTimer;
};

#endif // SWORDBEHAVIOUR_HPP_
