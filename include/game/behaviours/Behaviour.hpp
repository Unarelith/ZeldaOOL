/*
 * =====================================================================================
 *
 *       Filename:  Behaviour.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:20:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOUR_HPP_
#define BEHAVIOUR_HPP_

#include "SceneObject.hpp"

class Behaviour {
	public:
		Behaviour(const std::string &state = "") : m_state(state) {}
		virtual ~Behaviour() = default;

		virtual void reset(SceneObject &) {}

		virtual void action(SceneObject &object) = 0;

		const std::string &state() const { return m_state; }

	protected:
		std::string m_state;
};

#endif // BEHAVIOUR_HPP_
