/*
 * =====================================================================================
 *
 *       Filename:  AbstractView.hpp
 *
 *    Description:
 *
 *        Created:  26/01/2018 00:41:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ABSTRACTVIEW_HPP_
#define ABSTRACTVIEW_HPP_

#include <gk/gl/RenderTarget.hpp>

#include "SceneObjectList.hpp"

class AbstractView {
	public:
		virtual void draw(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) = 0;

		virtual void draw(const SceneObjectList &objectList, gk::RenderTarget &target, gk::RenderStates states) {
			for(auto &object : objectList) {
				draw(object, target, states);

				if (object.has<SceneObjectList>())
					draw(object.get<SceneObjectList>(), target, states);
			}
		}
};

#endif // ABSTRACTVIEW_HPP_
