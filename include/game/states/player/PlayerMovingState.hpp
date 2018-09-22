/*
 * =====================================================================================
 *
 *       Filename:  PlayerMovingState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:45:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERMOVINGSTATE_HPP_
#define PLAYERMOVINGSTATE_HPP_

#include "PlayerState.hpp"

class PlayerMovingState : public PlayerState {
	public:
		void onBegin(SceneObject &object) override;
		void onEnd(SceneObject &object) override;

		void update(SceneObject &object) override;
};

#endif // PLAYERMOVINGSTATE_HPP_
