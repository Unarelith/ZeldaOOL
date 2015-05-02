/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 02:23:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OCTOROKFACTORY_HPP_
#define OCTOROKFACTORY_HPP_

#include "SceneObject.hpp"

class OctorokFactory {
	public:
		static SceneObject create(float x, float y);
};

#endif // OCTOROKFACTORY_HPP_
