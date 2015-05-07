/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 02:00:33
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
		GamePadMovement(bool directionLocked = false)
			: m_directionLocked(directionLocked) {}
		
		void process(SceneObject &object) override;
		
	private:
		bool m_directionLocked;
};

#endif // GAMEPADMOVEMENT_HPP_
