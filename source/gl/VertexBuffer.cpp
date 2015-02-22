/*
 * =====================================================================================
 *
 *       Filename:  VertexBuffer.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:59:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer() {
	glGenBuffers(1, &m_id);
}

VertexBuffer::VertexBuffer(VertexBuffer &&vertexBuffer) {
	m_id = vertexBuffer.m_id;
	vertexBuffer.m_id = 0;
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_id);
}

void VertexBuffer::setData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VertexBuffer::updateData(GLintptr offset, GLsizeiptr size, const GLvoid *data) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void VertexBuffer::bind(const VertexBuffer *vertexBuffer) {
	if(vertexBuffer) {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->m_id);
	} else {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

