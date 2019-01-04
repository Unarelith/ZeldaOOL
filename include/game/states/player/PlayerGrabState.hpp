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
		PlayerGrabState(gk::SceneObject *weapon) { m_weapon = weapon; }

		void onBegin(gk::SceneObject &object) override;
		void onEnd(gk::SceneObject &object) override;

		void update(gk::SceneObject &object) override;

	private:
		void updateSprite(gk::SceneObject &object) override;

		gk::SceneObject *m_weapon = nullptr;
};

#endif // PLAYERGRABSTATE_HPP_
