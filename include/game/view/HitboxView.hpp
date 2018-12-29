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

#include "AbstractView.hpp"

class HitboxView : public AbstractView {
	public:
		void draw(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states);
};

#endif // HITBOXVIEW_HPP_


