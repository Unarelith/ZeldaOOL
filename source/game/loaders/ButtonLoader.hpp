/*
 * =====================================================================================
 *
 *       Filename:  ButtonLoader.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 17:14:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTONLOADER_HPP_
#define BUTTONLOADER_HPP_

#include <gk/core/XMLFile.hpp>
#include <gk/scene/Scene.hpp>

class ButtonLoader {
	public:
		static void load(tinyxml2::XMLElement *buttonElement, gk::Scene &scene);
};

#endif // BUTTONLOADER_HPP_
