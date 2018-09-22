/*
 * =====================================================================================
 *
 *       Filename:  PlayerSwordState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 19:06:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERSWORDSTATE_HPP_
#define PLAYERSWORDSTATE_HPP_

#include "PlayerState.hpp"

class PlayerSwordState : public PlayerState {
	public:
		PlayerSwordState(SceneObject *weapon) { m_weapon = weapon; }

		void onBegin(SceneObject &object) override;
		void onEnd(SceneObject &object) override;

		void update(SceneObject &object) override;

	private:
		void updateSprite(SceneObject &object) override;

		SceneObject *m_weapon = nullptr;
};

#endif // PLAYERSWORDSTATE_HPP_
