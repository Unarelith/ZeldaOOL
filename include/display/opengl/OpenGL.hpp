/*
 * =====================================================================================
 *
 *       Filename:  OpenGL.hpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 18:15:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
