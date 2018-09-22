/*
 * =====================================================================================
 *
 *       Filename:  PlayerGrabState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 19:57:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERGRABSTATE_HPP_
#define PLAYERGRABSTATE_HPP_

#include "PlayerState.hpp"

class PlayerGrabState : public PlayerState {
	public:
		PlayerGrabState(SceneObject *weapon) { m_weapon = weapon; }

		void onBegin(SceneObject &object) override;
		void onEnd(SceneObject &object) override;

		void update(SceneObject &object) override;

	private:
		void updateSprite(SceneObject &object) override;

		SceneObject *m_weapon = nullptr;
};

#endif // PLAYERGRABSTATE_HPP_
