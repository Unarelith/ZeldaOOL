/*
 * =====================================================================================
 *
 *       Filename:  OctorokMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 20:12:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OCTOROKMOVEMENT_HPP_
#define OCTOROKMOVEMENT_HPP_

#include "Movement.hpp"
#include "Timer.hpp"
#include "Vector2.hpp"

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

		Vector2f m_v = {0.0f, 0.0f};

		float m_movementCounter = 0;

		u16 m_randomMinTimeToWait = 1000;
		u16 m_randomMaxMovement = 48;
};

#endif // OCTOROKMOVEMENT_HPP_
