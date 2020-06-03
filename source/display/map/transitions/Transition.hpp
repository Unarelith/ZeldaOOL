/*
 * =====================================================================================
 *
 *       Filename:  Transition.hpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:42:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSITION_HPP_
#define TRANSITION_HPP_

#include <gk/gl/Drawable.hpp>

class Transition : public gk::Drawable {
	public:
		virtual ~Transition() = default;

		virtual void update() = 0;

		bool atEnd() const { return m_atEnd; }

		bool drawStatsBar() const { return m_drawStatsBar; }

	protected:
		bool m_atEnd = false;

		bool m_drawStatsBar = true;
};

#endif // TRANSITION_HPP_
