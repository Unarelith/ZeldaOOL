/*
 * =====================================================================================
 *
 *       Filename:  VertexArray.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 21:12:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef VERTEXARRAY_HPP_
#define VERTEXARRAY_HPP_

#include <vector>

#include "Types.hpp"
#include "Vertex.hpp"

class VertexArray {
	public:
		VertexArray();
		~VertexArray();
		
		void draw();
		
		Vertex &operator[](u32 index) { return m_vertices[index]; }
		const Vertex &operator[](u32 index) const { return m_vertices[index]; }
		
		void resize(u32 size) { m_vertices.resize(size); }
		
		enum PrimitiveType {
			Triangles
		};
		
		void setPrimitiveType(PrimitiveType primitiveType) { m_primitiveType = primitiveType; }
		
	private:
		std::vector<Vertex> m_vertices;
		
		PrimitiveType m_primitiveType;
};

#endif // VERTEXARRAY_HPP_
