/*
 * =====================================================================================
 *
 *       Filename:  LifetimeController.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:44:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMECONTROLLER_HPP_
#define LIFETIMECONTROLLER_HPP_

#include "AbstractController.hpp"
#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class LifetimeController : public AbstractController {
	public:
		void update(SceneObject &) override {}
		void update(SceneObjectList &objects) override;

		bool isGlobal() const override { return true; }
};

#endif // LIFETIMECONTROLLER_HPP_
