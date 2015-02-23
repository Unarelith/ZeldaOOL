/*
 * =====================================================================================
 *
 *       Filename:  VertexAttribute.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 15:35:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef VERTEXATTRIBUTE_HPP_
#define VERTEXATTRIBUTE_HPP_

#include "OpenGL.hpp"

struct VertexAttribute {
	GLfloat coord2d[2];
	GLfloat texCoord[2];
	GLfloat colorMod[4];
};

#endif // VERTEXATTRIBUTE_HPP_
