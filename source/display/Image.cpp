/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:
 *
 *        Created:  20/09/2014 16:22:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/gl/Shader.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Config.hpp"
#include "Image.hpp"

void Image::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (states.shader) {
		gk::Shader::bind(states.shader);
		states.shader->setUniform("u_paletteID", m_paletteID);
		gk::Shader::bind(nullptr);
	}

	gk::Image::draw(target, states);
}

