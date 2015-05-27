/*
 * =====================================================================================
 *
 *       Filename:  BattleSystem.hpp
 *
 *    Description:  
 *
 *        Created:  26/05/2015 12:42:11
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLESYSTEM_HPP_
#define BATTLESYSTEM_HPP_

#include "SceneObject.hpp"

class BattleSystem {
	public:
		static void update(SceneObject &object);
		
		static void hurt(SceneObject &attacker, SceneObject &receiver);
};

#endif // BATTLESYSTEM_HPP_
