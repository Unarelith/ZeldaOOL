/*
 * =====================================================================================
 *
 *       Filename:  Renderer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 22:49:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "Drawable.hpp"

class Renderer {
	public:
		virtual ~Renderer() {}
		
		virtual void clear() = 0;
		
		virtual void render() = 0;
		
		virtual void draw(Drawable &drawable) = 0;
};

#endif // RENDERER_HPP_
