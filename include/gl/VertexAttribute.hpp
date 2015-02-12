/*
 * =====================================================================================
 *
 *       Filename:  VertexAttribute.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:13:48
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
	GLfloat color[4];
};

#endif // VERTEXATTRIBUTE_HPP_
