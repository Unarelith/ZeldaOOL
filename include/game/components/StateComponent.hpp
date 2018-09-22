/*
 * =====================================================================================
 *
 *       Filename:  StateComponent.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 17:43:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATECOMPONENT_HPP_
#define STATECOMPONENT_HPP_

#include <memory>

#include "IState.hpp"

class StateComponent {
	using StatePtr = std::shared_ptr<IState>;

	public:
		void update(SceneObject &object);

		void setState(SceneObject &object, StatePtr state);

	private:
		StatePtr m_state;
};

#endif // STATECOMPONENT_HPP_
