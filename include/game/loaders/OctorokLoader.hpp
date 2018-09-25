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

#include "Scene.hpp"
#include "XMLFile.hpp"

class OctorokLoader {
	public:
		static void load(XMLElement *octorokElement, Scene &scene);
};

#endif // OCTOROKLOADER_HPP_
