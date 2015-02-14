/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 15:02:57
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "Types.hpp"

class PositionComponent {
	public:
		PositionComponent(float _x, float _y, u16 _width, u16 _height)
			: x(_x), y(_y), width(_width), height(_height) {}
		
		float x = 0;
		float y = 0;
		
		u16 width = 0;
		u16 height = 0;
};

#endif // POSITIONCOMPONENT_HPP_
