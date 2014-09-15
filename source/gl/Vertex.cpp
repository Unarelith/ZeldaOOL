/*
 * =====================================================================================
 *
 *       Filename:  Vertex.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 21:12:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Vertex.hpp"

Vertex::Vertex() {
	
}

Vertex::Vertex(const Vector2f &_position) {
	position = _position;
}

Vertex::Vertex(const Vector2f &_position, const Vector2f &_texCoords) {
	position = _position;
	texCoords = _texCoords;
}

Vertex::~Vertex() {
}

