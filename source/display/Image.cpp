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
#include <SFML/Graphics/Shader.hpp>

#include <gk/resource/ResourceHandler.hpp>

#include "Config.hpp"
#include "Image.hpp"

void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	if (states.shader) {
		sf::Shader::bind(states.shader);
		// FIXME
		// states.shader->setUniform("u_paletteID", m_paletteID);
		sf::Shader::bind(nullptr);
	}

	gk::Image::draw(target, states);
}

