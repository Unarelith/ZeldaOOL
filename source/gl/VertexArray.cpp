/*
 * =====================================================================================
 *
 *       Filename:  VertexArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 21:12:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <GL/gl.h>

#include "VertexArray.hpp"

VertexArray::VertexArray() {
	
}

VertexArray::~VertexArray() {
}

void VertexArray::draw() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	const char *data = reinterpret_cast<const char *>(&m_vertices[0]);
	glVertexPointer(2, GL_FLOAT, sizeof(Vertex), data);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), data + 4);	
	
	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
	
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

