/*
 * =====================================================================================
 *
 *       Filename:  RupeeCollectable.cpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 18:21:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "Player.hpp"
#include "RupeeCollectable.hpp"

RupeeCollectable::RupeeCollectable(float x, float y, u16 rupees) {
	m_rupees = rupees;
	
	switch(m_rupees) {
		case 1:  load("collectables-rupees1",  x, y); break;
		case 5:  load("collectables-rupees5",  x, y); break;
		case 30: load("collectables-rupees30", x, y); break;
	}
}

void RupeeCollectable::action() {
	switch(m_rupees) {
		case 1:  AudioPlayer::playEffect("getRupee");   break;
		case 5:  AudioPlayer::playEffect("getRupees5"); break;
		case 30: AudioPlayer::playEffect("getRupees5"); break;
	}
	
	Player::player.inventory().addRupees(m_rupees);
}

