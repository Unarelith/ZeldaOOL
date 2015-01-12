/*
 * =====================================================================================
 *
 *       Filename:  VertexBuffer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2014 13:56:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
		
		void setData(GLsizeiptr size, const GLvoid *data, GLenum usage);
		void updateData(GLintptr offset, GLsizeiptr size, const GLvoid *data);
		
		static void bind(const VertexBuffer *vertexBuffer);
		
		GLuint id() const { return m_id; }
		
	private:
		GLuint m_id;
};

#endif // VERTEXBUFFER_HPP_
