/*
 * =====================================================================================
 *
 *       Filename:  Shader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 14:42:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>

#include "Debug.hpp"
#include "Shader.hpp"

Shader::Shader() {
}

Shader::Shader(const char *vertexFilename, const char *fragmentFilename) {
	load(vertexFilename, fragmentFilename);
}

Shader::~Shader() {
	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);
	glDeleteProgram(m_program);
}

void Shader::load(const char *vertexFilename, const char *fragmentFilename) {
	compile(GL_VERTEX_SHADER, m_vertexShader, vertexFilename);
	compile(GL_FRAGMENT_SHADER, m_fragmentShader, fragmentFilename);
	
	m_program = glCreateProgram();
	
	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	
	glLinkProgram(m_program);
	
	GLint linkOK = GL_FALSE;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linkOK);
	if(!linkOK){
		GLint errorSize = 0;
		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &errorSize);
		
		char *errorMsg = new char[errorSize + 1];
		
		glGetProgramInfoLog(m_program, errorSize, &errorSize, errorMsg);
		errorMsg[errorSize] = '\0';
		
		error("Program %u link %s", m_program, errorMsg);
		
		delete[] errorMsg;
		glDeleteProgram(m_program);
		
		exit(EXIT_FAILURE);
	}
}

void Shader::compile(GLenum type, GLuint &shader, const char *filename) {
	shader = glCreateShader(type);
	
	std::ifstream file(filename);
	if(!file) {
		error("Failed to open %s", filename);
		glDeleteShader(type);
		exit(EXIT_FAILURE);
	}
	
	std::string line;
	std::string sourceCode;
	
	while(getline(file, line)) sourceCode += line + '\n';
	
	file.close();
	
	const GLchar *sourceCodeString = sourceCode.c_str();
	
	glShaderSource(shader, 1, &sourceCodeString, NULL);
	
	glCompileShader(shader);
	
	GLint compileOK = GL_FALSE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileOK);
	if(!compileOK) {
		GLint errorSize = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorSize);
		
		char *errorMsg = new char[errorSize + 1];
		
		glGetShaderInfoLog(shader, errorSize, &errorSize, errorMsg);
		errorMsg[errorSize] = '\0';
		
		error("Shader \"%s\" %s", filename, errorMsg);
		
		delete[] errorMsg;
		glDeleteShader(shader);
		
		exit(EXIT_FAILURE);
	}
}

GLint Shader::attrib(const char *attribName) {
	GLint attrib = glGetAttribLocation(m_program, attribName);
	
	if(attrib == -1) {
		error("Could not bind '%s' attribute", attribName);
		exit(EXIT_FAILURE);
	}
	
	return attrib;
}

GLint Shader::uniform(const char *uniformName) {
	GLint uniform = glGetUniformLocation(m_program, uniformName);
	
	if(uniform == -1) {
		error("Could not bind uniform '%s' attribute", uniformName);
		exit(EXIT_FAILURE);
	}
	
	return uniform;
}

