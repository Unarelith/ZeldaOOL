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

		template<typename T, typename... Args>
		void setState(SceneObject &object, Args &&...args) {
			setState(object, std::make_shared<T>(std::forward<Args>(args)...));
		}

	private:
		void setState(SceneObject &object, StatePtr state);

		StatePtr m_state;
};

#endif // STATECOMPONENT_HPP_
