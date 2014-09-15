/*
 * =====================================================================================
 *
 *       Filename:  Vertex.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 21:11:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include "Vector2.hpp"

class Vertex {
	public:
		Vertex();
		Vertex(const Vector2f &_position);
		Vertex(const Vector2f &_position, const Vector2f &_texCoords);
		~Vertex();
		
		Vector2f position;
		Vector2f texCoords;
};

#endif // VERTEX_HPP_
