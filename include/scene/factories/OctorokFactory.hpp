/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 01:05:50
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
