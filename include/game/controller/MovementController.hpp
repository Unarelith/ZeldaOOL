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

#include "AbstractController.hpp"
#include "SceneObject.hpp"

class MovementController : public AbstractController {
	public:
		void update(SceneObject &object) override;
};

#endif // MOVEMENTCONTROLLER_HPP_
