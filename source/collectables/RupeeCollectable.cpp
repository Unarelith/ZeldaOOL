/*
 * =====================================================================================
 *
 *       Filename:  RupeeCollectable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 18:21:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "RupeeCollectable.hpp"
#include "Sound.hpp"

RupeeCollectable::RupeeCollectable(float x, float y, u16 rupees) {
	m_rupees = rupees;
	
	switch(m_rupees) {
		case 1:		load(x, y, "graphics/collectables/rupees1.png");	break;
		case 5:		load(x, y, "graphics/collectables/rupees5.png");	break;
		case 30:	load(x, y, "graphics/collectables/rupees30.png");	break;
	}
}

RupeeCollectable::~RupeeCollectable() {
}

void RupeeCollectable::action() {
	switch(m_rupees) {
		case 1:		Sound::Effect::getRupee.play();		break;
		case 5:		Sound::Effect::getRupees5.play();	break;
		case 30:	Sound::Effect::getRupees5.play();	break;
	}
	
	CharacterManager::player.addRupees(m_rupees);
}

