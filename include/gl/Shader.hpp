/*
 * =====================================================================================
 *
 *       Filename:  Shader.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:55:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>

#include <glm/glm.hpp>

#include "OpenGL.hpp"

class Shader {
	public:
		Shader() = default;
		Shader(const Shader &shader) = default;
		Shader(Shader &&shader);
		Shader(const std::string &vertexFilename, const std::string &fragementFilename);
		~Shader();
		
		Shader &operator=(const Shader &shader) = default;
		
		void loadFromFile(const std::string &vertexFilename, const std::string &fragementFilename);
		
		void compileShader(GLenum type, GLuint &shader, const std::string &filename);
		
		GLint attrib(const std::string &name);
		GLint uniform(const std::string &name);
		
		void enableVertexAttribArray(const std::string &name);
		void disableVertexAttribArray(const std::string &name);
		
		void setUniform(const std::string &name, int n);
		void setUniform(const std::string &name, float d, float e);
		void setUniform(const std::string &name, const glm::mat4 &matrix);
		
		static void bind(const Shader *shader);
		static Shader *currentShader;
		
	private:
		GLuint m_vertexShader = 0;
		GLuint m_fragmentShader = 0;
		GLuint m_program = 0;
};

#endif // SHADER_HPP_
