/*
 * =====================================================================================
 *
 *       Filename:  OpenGLTestState.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 23:00:19
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef OPENGLTESTSTATE_HPP_
#define OPENGLTESTSTATE_HPP_

#include "ApplicationState.hpp"

#include "Texture.hpp"
#include "VertexBuffer.hpp"

class OpenGLTestState : public ApplicationState {
	private:
		void update() override {};
		
		void draw() override;
		
	private:
		Texture m_texture{"graphics/characters/link.png"};
		
		VertexBuffer m_vbo;
};

#endif // OPENGLTESTSTATE_HPP_
