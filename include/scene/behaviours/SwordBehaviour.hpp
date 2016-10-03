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
		SwordBehaviour();

		void action(SceneObject &sword) override;

		void updateHitboxes(SceneObject &sword);
		void updateSprite(SceneObject &sword);

	private:
		bool m_keyReleased = false;

		Timer m_loadingTimer;
		bool m_isLoaded = false;

		Timer m_spinTimer;
		u16 m_spinCurrentFrame = 0;
		u16 m_spinFrameCounter = 0;
};

#endif // SWORDBEHAVIOUR_HPP_
