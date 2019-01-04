/*
 * =====================================================================================
 *
 *       Filename:  LifetimeController.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:44:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMECONTROLLER_HPP_
#define LIFETIMECONTROLLER_HPP_

#include <gk/scene/controller/AbstractController.hpp>
#include <gk/scene/SceneObject.hpp>
#include <gk/scene/SceneObjectList.hpp>

class LifetimeController : public gk::AbstractController {
	public:
		void update(gk::SceneObject &) override {}
		void update(gk::SceneObjectList &objects) override;

		bool isGlobal() const override { return true; }
};

#endif // LIFETIMECONTROLLER_HPP_
