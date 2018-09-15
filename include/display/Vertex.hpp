/*
 * =====================================================================================
 *
 *       Filename:  Vertex.hpp
 *
 *    Description:
 *
 *        Created:  19/06/2018 23:37:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include "OpenGL.hpp"

struct Vertex {
	GLfloat coord2d[4]    = {0, 0, 0, 1};
	GLfloat color[4]      = {0, 0, 0, 1};
	GLfloat texCoord[2]   = {-1, -1};
};

#endif // VERTEX_HPP_
