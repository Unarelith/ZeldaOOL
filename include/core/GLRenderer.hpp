/*
 * =====================================================================================
 *
 *       Filename:  GLRenderer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 22:51:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GLRENDERER_HPP_
#define GLRENDERER_HPP_

#include "Renderer.hpp"

class GLRenderer : public Renderer {
	public:
		GLRenderer();
		~GLRenderer();
		
		void clear();
		
		void update();
		
		void draw(Drawable &drawable);
};

#endif // GLRENDERER_HPP_
