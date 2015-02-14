/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:35:32
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DRAWINGSYSTEM_HPP_
#define DRAWINGSYSTEM_HPP_

#include "SceneObject.hpp"

class DrawingSystem {
	public:
		void draw(SceneObject &object);
};

#endif // DRAWINGSYSTEM_HPP_
