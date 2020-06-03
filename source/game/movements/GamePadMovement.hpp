/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 02:00:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPADMOVEMENT_HPP_
#define GAMEPADMOVEMENT_HPP_

#include <gk/scene/movement/Movement.hpp>

class GamePadMovement : public gk::Movement {
	public:
		void process(gk::SceneObject &object) override;
};

#endif // GAMEPADMOVEMENT_HPP_
