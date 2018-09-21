/*
 * =====================================================================================
 *
 *       Filename:  SpriteView.hpp
 *
 *    Description:
 *
 *        Created:  26/01/2018 01:29:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITEVIEW_HPP_
#define SPRITEVIEW_HPP_

#include "AbstractView.hpp"

class SpriteView : public AbstractView {
	public:
		void draw(const SceneObject &object, RenderTarget &target, RenderStates states) const override;
};

#endif // SPRITEVIEW_HPP_
