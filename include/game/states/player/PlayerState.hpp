/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:13:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERSTATE_HPP_
#define PLAYERSTATE_HPP_

#include "IState.hpp"

class PlayerState : public IState {
	public:
		void update(SceneObject &object) override;

	protected:
		void weaponAction(SceneObject &player);
		virtual void updateSprite(SceneObject &player);

		std::string m_state = "Standing";
};

#endif // PLAYERSTATE_HPP_
