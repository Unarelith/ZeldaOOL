/*
 * =====================================================================================
 *
 *       Filename:  MovementController.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:27:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCONTROLLER_HPP_
#define MOVEMENTCONTROLLER_HPP_

#include <gk/scene/controller/AbstractController.hpp>

class MovementController : public gk::AbstractController {
	public:
		void update(gk::SceneObject &object) override;
};

#endif // MOVEMENTCONTROLLER_HPP_
