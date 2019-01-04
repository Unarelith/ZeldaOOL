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

#include <gk/scene/controller/AbstractController.hpp>
#include <gk/scene/SceneObject.hpp>

class BattleController : public gk::AbstractController {
	public:
		void update(gk::SceneObject &object) override;

		static void hurt(gk::SceneObject &attacker, gk::SceneObject &receiver);
};

#endif // BATTLECONTROLLER_HPP_
