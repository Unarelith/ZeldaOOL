/*
 * =====================================================================================
 *
 *       Filename:  NPC.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/01/2015 07:06:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <glm/vec2.hpp>

#include "ApplicationStateStack.hpp"
#include "DialogState.hpp"
#include "Keyboard.hpp"
#include "NPC.hpp"
#include "Player.hpp"

NPC::NPC(const std::string &textureName, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(textureName, x, y, width, height, direction);
}

void NPC::load(const std::string &textureName, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Character::load(textureName, x, y, width, height, direction);
	
	m_defaultDirection = m_direction;
	
	addAnimation({0, 4}, 150);
	addAnimation({1, 5}, 150);
	addAnimation({2, 6}, 150);
	addAnimation({3, 7}, 150);
}

bool NPC::playerInFrontOfThis() {
	glm::ivec2 position(m_x / 16, m_y / 16);
	
	glm::ivec2 playerPosition[4] = {
		{Player::player.x() / 16 + 0.5, Player::player.y() / 16 + 1},
		{Player::player.x() / 16 + 1,   Player::player.y() / 16 + 0.7},
		{Player::player.x() / 16,       Player::player.y() / 16 + 0.7},
		{Player::player.x() / 16 + 0.5, Player::player.y() / 16}
	};
	
	return playerPosition[Player::player.direction()] == position;
}

void NPC::update() {
	m_direction = m_defaultDirection;
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A) && playerInFrontOfThis()) {
		m_direction = 3 - Player::player.direction();
		
		// FIXME: TO REMOVE LATER
		ApplicationStateStack::getInstance().push<DialogState>(ApplicationStateStack::getInstance().top(), "Il faut que tu sauves Nayru!");
	}
}

void NPC::draw() {
	playAnimation(m_x, m_y, m_direction);
}

