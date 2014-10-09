/*
 * =====================================================================================
 *
 *       Filename:  Shader.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 14:42:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SHADER_HPP_
#define SHADER_HPP_

#include "OpenGL.hpp"

class Shader {
	public:
		Shader();
		Shader(const char *vertexFilename, const char *fragementFilename);
		~Shader();
		
		void load(const char *vertexFilename, const char *fragementFilename);
		
		void compile(GLenum type, GLuint &shader, const char *filename);
		
		GLint attrib(const char *attribName);
		GLint uniform(const char *uniformName);
		
		void enableVertexAttribArray(const char *attribName);
		void disableVertexAttribArray(const char *attribName);
		
		void useProgram() { glUseProgram(m_program); }
		
		GLint program() const { return m_program; }
		
		bool isLoaded() const { return m_isLoaded; }
		
	private:
		GLuint m_vertexShader;
		GLuint m_fragmentShader;
		GLuint m_program;
		
		bool m_isLoaded;
};

#endif // SHADER_HPP_
