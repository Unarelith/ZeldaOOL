/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:54:31
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPADMOVEMENT_HPP_
#define GAMEPADMOVEMENT_HPP_

#include "Movement.hpp"

class GamePadMovement : public Movement {
	public:
		void process(SceneObject &object) override;
};

#endif // GAMEPADMOVEMENT_HPP_
