/*
 * =====================================================================================
 *
 *       Filename:  OpenGL.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 18:15:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef OPENGL_HPP_
#define OPENGL_HPP_

#ifdef __APPLE__
	#include <OpenGL/gl.h>
#else
	#ifdef __MINGW32__
		#include <GL/glew.h>
	#else
		#include <GL/gl.h>
	#endif
#endif

#endif // OPENGL_HPP_
