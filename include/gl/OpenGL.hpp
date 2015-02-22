/*
 * =====================================================================================
 *
 *       Filename:  OpenGL.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:08:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OPENGL_HPP_
#define OPENGL_HPP_

#define GL_GLEXT_PROTOTYPES

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
