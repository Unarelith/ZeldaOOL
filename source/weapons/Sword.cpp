/*
 * =====================================================================================
 *
 *       Filename:  Sword.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 21:13:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Sword.hpp"

Sword::Sword() : Weapon("graphics/animations/sword.png", 16, 16) {
	addAnimation({0, 4, 8, 8}, 100);
	addAnimation({1, 5, 9, 9}, 100);
	addAnimation({2, 6, 10, 10}, 100);
	addAnimation({3, 7, 11, 11}, 100);
}

Sword::~Sword() {
}

void Sword::action() {
}

