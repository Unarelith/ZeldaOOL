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
#include "SoundEffect.hpp"

RupeeCollectable::RupeeCollectable(float x, float y, u16 rupees) {
	m_rupees = rupees;
	
	switch(m_rupees) {
		case 1:  load(x, y, "collectables-rupees1");  break;
		case 5:  load(x, y, "collectables-rupees5");  break;
		case 30: load(x, y, "collectables-rupees30"); break;
	}
}

RupeeCollectable::~RupeeCollectable() {
}

void RupeeCollectable::action() {
	switch(m_rupees) {
		case 1:  SoundEffect::play("getRupee");   break;
		case 5:  SoundEffect::play("getRupees5"); break;
		case 30: SoundEffect::play("getRupees5"); break;
	}
	
	CharacterManager::player.inventory().addRupees(m_rupees);
}

