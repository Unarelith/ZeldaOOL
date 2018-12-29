/*
 * =====================================================================================
 *
 *       Filename:  OctorokLoader.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:29:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OCTOROKLOADER_HPP_
#define OCTOROKLOADER_HPP_

#include <gk/core/XMLFile.hpp>

#include "Scene.hpp"

class OctorokLoader {
	public:
		static void load(tinyxml2::XMLElement *octorokElement, Scene &scene);
};

#endif // OCTOROKLOADER_HPP_
