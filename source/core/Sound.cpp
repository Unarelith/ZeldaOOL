/*
 * =====================================================================================
 *
 *       Filename:  Sound.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/08/2014 02:18:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Sound.hpp"

BackgroundMusic Sound::Music::plain;

SoundEffect Sound::Effect::chest;

SoundEffect Sound::Effect::grassDestroy;

SoundEffect Sound::Effect::swordCharge;
SoundEffect Sound::Effect::swordSlash1;
SoundEffect Sound::Effect::swordSpin;
SoundEffect Sound::Effect::swordTap;

void Sound::init() {
	Sound::Music::init();
	
	Sound::Effect::init();
}

void Sound::Music::init() {
	plain.open("audio/music/plain.ogg");
}

void Sound::Effect::init() {
	chest.load("audio/effects/chest.wav");
	
	grassDestroy.load("audio/effects/grassDestroy.wav");
	
	swordCharge.load("audio/effects/swordCharge.wav");
	swordSlash1.load("audio/effects/swordSlash1.wav");
	swordSpin.load("audio/effects/swordSpin.wav");
	swordTap.load("audio/effects/swordTap.wav");
}

