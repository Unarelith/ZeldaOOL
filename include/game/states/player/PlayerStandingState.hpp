/*
 * =====================================================================================
 *
 *       Filename:  PlayerStandingState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:38:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERSTANDINGSTATE_HPP_
#define PLAYERSTANDINGSTATE_HPP_

#include "PlayerState.hpp"

class PlayerStandingState : public PlayerState {
	public:
		void onBegin(SceneObject &object) override;
		void onEnd(SceneObject &object) override;

		void update(SceneObject &object) override;
};

#endif // PLAYERSTANDINGSTATE_HPP_
