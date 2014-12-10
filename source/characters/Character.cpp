/*
 * =====================================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2014 01:25:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameState.hpp"
#include "Character.hpp"
#include "Player.hpp"

Character::Character() {
}

Character::Character(std::string filename, u16 frameWidth, u16 frameHeight) {
	load(filename, frameWidth, frameHeight);
}

Character::~Character() {
}

void Character::load(std::string filename, u16 frameWidth, u16 frameHeight) {
	Movable::load(filename, frameWidth, frameHeight);
}

bool Character::inCollisionWith(Character &character) {
	sf::FloatRect rect1 = sf::FloatRect(getPosition().x, getPosition().y, m_frameWidth, m_frameHeight);
	sf::FloatRect rect2 = sf::FloatRect(character.getPosition().x, character.getPosition().y, character.m_frameWidth, character.m_frameHeight);
	return rect1.intersects(rect2);
}

