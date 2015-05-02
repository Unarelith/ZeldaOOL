/*
 * =====================================================================================
 *
 *       Filename:  OctorokMovement.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 20:12:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OCTOROKMOVEMENT_HPP_
#define OCTOROKMOVEMENT_HPP_

#include "Movement.hpp"
#include "Timer.hpp"

class OctorokMovement : public Movement {
	public:
		enum class State {
			Standing,
			Moving
		};
		
		void reset(SceneObject &object);
		
		void process(SceneObject &object) override;
		
	private:
		State m_state = State::Standing;
		
		Timer m_timer;
		
		s8 m_vx = 0;
		s8 m_vy = 0;
		
		float m_movementCounter = 0;
		
		u16 m_randomMinTimeToWait = 1000;
		u16 m_randomMaxMovement = 48;
};

#endif // OCTOROKMOVEMENT_HPP_
