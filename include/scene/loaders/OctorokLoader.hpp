/*
 * =====================================================================================
 *
 *       Filename:  OctorokLoader.hpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:29:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OCTOROKLOADER_HPP_
#define OCTOROKLOADER_HPP_

#include "SceneObjectList.hpp"
#include "XMLFile.hpp"

class OctorokLoader {
	public:
		static void load(XMLElement *octorokElement, SceneObjectList &objectList);
};

#endif // OCTOROKLOADER_HPP_
