/*
 * =====================================================================================
 *
 *       Filename:  PlayerMapCollisionAction.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2018 21:06:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERMAPCOLLISIONACTION_HPP_
#define PLAYERMAPCOLLISIONACTION_HPP_

#include "SceneObject.hpp"

class PlayerMapCollisionAction {
	public:
		void operator()(SceneObject &player, SceneObject &object, bool);
};

#endif // PLAYERMAPCOLLISIONACTION_HPP_
