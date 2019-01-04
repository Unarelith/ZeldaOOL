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
		void update(gk::SceneObject &object);

		template<typename T, typename... Args>
		auto setState(gk::SceneObject &object, Args &&...args) -> typename std::enable_if<std::is_base_of<IState, T>::value, void>::type {
			setState(object, std::make_shared<T>(std::forward<Args>(args)...));
		}

	private:
		void setState(gk::SceneObject &object, StatePtr state);

		StatePtr m_state;
};

#endif // STATECOMPONENT_HPP_
