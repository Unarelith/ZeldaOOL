/*
 * =====================================================================================
 *
 *       Filename:  BattleController.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2015 12:42:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLECONTROLLER_HPP_
#define BATTLECONTROLLER_HPP_

#include "AbstractController.hpp"
#include "SceneObject.hpp"

class BattleController : public AbstractController {
	public:
		void update(SceneObject &object) override;

		static void hurt(SceneObject &attacker, SceneObject &receiver);
};

#endif // BATTLECONTROLLER_HPP_
