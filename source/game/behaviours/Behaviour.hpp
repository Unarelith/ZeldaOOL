/*
 * =====================================================================================
 *
 *       Filename:  Behaviour.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 15:20:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOUR_HPP_
#define BEHAVIOUR_HPP_

#include <gk/scene/SceneObject.hpp>
#include <gk/scene/behaviour/Behaviour.hpp>

class Behaviour : public gk::Behaviour {
	public:
		Behaviour(const std::string &state = "") : m_state(state) {}
		virtual ~Behaviour() = default;

		virtual void reset(gk::SceneObject &) {}

		const std::string &state() const { return m_state; }

	protected:
		std::string m_state;
};

#endif // BEHAVIOUR_HPP_
