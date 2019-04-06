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

#include <gk/scene/view/AbstractView.hpp>

class SpriteView : public gk::AbstractView {
	public:
		void draw(const gk::SceneObject &object, sf::RenderTarget &target, sf::RenderStates states) override;
};

#endif // SPRITEVIEW_HPP_
