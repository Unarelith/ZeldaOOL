/*
 * =====================================================================================
 *
 *       Filename:  SwordBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:44:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SWORDBEHAVIOUR_HPP_
#define SWORDBEHAVIOUR_HPP_

#include <gk/core/Timer.hpp>

#include "Behaviour.hpp"

class SwordBehaviour : public Behaviour {
	public:
		SwordBehaviour();

		void update(gk::SceneObject &sword) override;

		void updateHitboxes(gk::SceneObject &sword);
		void updateSprite(gk::SceneObject &sword);

	private:
		bool m_keyReleased = false;

		gk::Timer m_loadingTimer;

		gk::Timer m_spinTimer;
		u16 m_spinCurrentFrame = 0;
		u16 m_spinFrameCounter = 0;
};

#endif // SWORDBEHAVIOUR_HPP_
