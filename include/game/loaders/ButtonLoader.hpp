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

#include "Scene.hpp"
#include "XMLFile.hpp"

class ButtonLoader {
	public:
		static void load(XMLElement *buttonElement, Scene &scene);
};

#endif // BUTTONLOADER_HPP_
