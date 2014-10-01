/*
 * =====================================================================================
 *
 *       Filename:  ShaderManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2014 14:44:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SHADERMANAGER_HPP_
#define SHADERMANAGER_HPP_

#include <stack>

#include "Shader.hpp"

namespace ShaderManager {
	extern std::stack<Shader*> shaders;
	
	Shader &currentShader();
	void push(Shader &shader);
	void pop();
};

#endif // SHADERMANAGER_HPP_
