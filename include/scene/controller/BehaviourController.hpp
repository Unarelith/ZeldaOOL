/*
 * =====================================================================================
 *
 *       Filename:  BehaviourController.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:26:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURCONTROLLER_HPP_
#define BEHAVIOURCONTROLLER_HPP_

#include "AbstractController.hpp"
#include "SceneObject.hpp"

class BehaviourController : public AbstractController {
	public:
		void reset(SceneObject &object) override;

		void update(SceneObject &object) override;
};

#endif // BEHAVIOURCONTROLLER_HPP_
