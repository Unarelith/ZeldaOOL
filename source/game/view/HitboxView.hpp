/*
 * =====================================================================================
 *
 *       Filename:  HitboxView.hpp
 *
 *    Description:
 *
 *        Created:  21/04/2018 09:23:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HITBOXVIEW_HPP_
#define HITBOXVIEW_HPP_

#include <gk/scene/view/AbstractView.hpp>

class HitboxView : public gk::AbstractView {
	public:
		void draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states);
};

#endif // HITBOXVIEW_HPP_
