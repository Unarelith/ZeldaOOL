/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:54:31
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
