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
	
	addAnimation({0, 4}, 150);
	addAnimation({1, 5}, 150);
	addAnimation({2, 6}, 150);
	addAnimation({3, 7}, 150);
}

void NPC::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& floor(Player::player.x() / 16) == floor(m_x / 16)
	&& floor(Player::player.y() / 16) == floor(m_y / 16 + 1)) {
		// FIXME: TO REMOVE LATER
		ApplicationStateStack::getInstance().push<DialogState>(ApplicationStateStack::getInstance().top(), "Il faut que tu sauves Nayru!");
	}
}

void NPC::draw() {
	playAnimation(m_x, m_y, m_direction);
}

