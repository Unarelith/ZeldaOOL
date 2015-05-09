/*
 * =====================================================================================
 *
 *       Filename:  VertexBuffer.hpp
 *
 *    Description:  
 *
 *        Created:  26/12/2014 13:56:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VERTEXBUFFER_HPP_
#define VERTEXBUFFER_HPP_

#include "OpenGL.hpp"

class VertexBuffer {
	public:
		VertexBuffer();
		VertexBuffer(const VertexBuffer &) = delete;
		VertexBuffer(VertexBuffer &&vertexBuffer);
		~VertexBuffer();
		
		VertexBuffer &operator=(const VertexBuffer &) = delete;
		VertexBuffer &operator=(VertexBuffer &&vertexBuffer);
		
		void setData(GLsizeiptr size, const GLvoid *data, GLenum usage);
		void updateData(GLintptr offset, GLsizeiptr size, const GLvoid *data);
		
		static void bind(const VertexBuffer *vertexBuffer);
		
		GLuint id() const { return m_id; }
		
	private:
		GLuint m_id = 0;
};

#endif // VERTEXBUFFER_HPP_
