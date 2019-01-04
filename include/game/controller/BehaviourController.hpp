/*
 * =====================================================================================
 *
 *       Filename:  BehaviourController.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:26:32
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURCONTROLLER_HPP_
#define BEHAVIOURCONTROLLER_HPP_

#include <gk/scene/controller/AbstractController.hpp>
#include <gk/scene/SceneObject.hpp>

class BehaviourController : public gk::AbstractController {
	public:
		void reset(gk::SceneObject &object) override;

		void update(gk::SceneObject &object) override;
};

#endif // BEHAVIOURCONTROLLER_HPP_
