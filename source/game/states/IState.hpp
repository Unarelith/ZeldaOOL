/*
 * =====================================================================================
 *
 *       Filename:  IState.hpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 17:57:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ISTATE_HPP_
#define ISTATE_HPP_

#include <gk/scene/SceneObject.hpp>

class IState {
	public:
		virtual void onBegin(gk::SceneObject &) {}
		virtual void onEnd(gk::SceneObject &) {}

		virtual void update(gk::SceneObject &object) = 0;
};

#endif // ISTATE_HPP_
