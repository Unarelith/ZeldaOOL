/*
 * =====================================================================================
 *
 *       Filename:  ShaderManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2014 15:00:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ShaderManager.hpp"

std::stack<Shader*> ShaderManager::shaders;

Shader &ShaderManager::currentShader() {
	return *shaders.top();
}

void ShaderManager::push(Shader &shader) {
	shaders.push(&shader);
	
	Shader::bind(&currentShader());
}

void ShaderManager::pop() {
	shaders.pop();
	
	if(shaders.size() > 0) {
		Shader::bind(&currentShader());
	}
}

