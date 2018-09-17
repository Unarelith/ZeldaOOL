/*
 * =====================================================================================
 *
 *       Filename:  VertexBuffer.hpp
 *
 *    Description:
 *
 *        Created:  15/12/2014 17:09:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VERTEXBUFFER_HPP_
#define VERTEXBUFFER_HPP_

#include "OpenGL.hpp"

class VertexBuffer {
	public:
		VertexBuffer();
		VertexBuffer(const VertexBuffer &);
		VertexBuffer(VertexBuffer &&);
		~VertexBuffer() noexcept;

		VertexBuffer &operator=(const VertexBuffer &);
		VertexBuffer &operator=(VertexBuffer &&) = default;

		void setData(GLsizeiptr size, const GLvoid *data, GLenum usage) const;
		void updateData(GLintptr offset, GLsizeiptr size, const GLvoid *data) const;

		void setAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) const;

		static void bind(const VertexBuffer *vertexBuffer);

	private:
		GLuint m_id = 0;

		bool m_isCopy = false;
};

#endif // VERTEXBUFFER_HPP_
