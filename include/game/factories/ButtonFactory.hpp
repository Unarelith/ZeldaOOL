/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.hpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 01:49:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTONFACTORY_HPP_
#define BUTTONFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class ButtonFactory {
	public:
		static gk::SceneObject create(u16 tileX, u16 tileY);

	private:
		static void buttonAction(gk::SceneObject &button, gk::SceneObject &object, bool inCollision);
};

#endif // BUTTONFACTORY_HPP_
