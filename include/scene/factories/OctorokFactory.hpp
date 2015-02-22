/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 01:05:50
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
