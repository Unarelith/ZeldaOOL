/*
 * =====================================================================================
 *
 *       Filename:  Sound.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Sound.hpp"

BackgroundMusic Sound::Music::indoor;
BackgroundMusic Sound::Music::plain;
BackgroundMusic Sound::Music::underground;

SoundEffect Sound::Effect::chest;

SoundEffect Sound::Effect::dialogContinue;

SoundEffect Sound::Effect::getHeart;
SoundEffect Sound::Effect::getRupee;
SoundEffect Sound::Effect::getRupees5;

SoundEffect Sound::Effect::grassDestroy;

SoundEffect Sound::Effect::itemNew;

SoundEffect Sound::Effect::mapStairs;

SoundEffect Sound::Effect::menuClose;
SoundEffect Sound::Effect::menuCursor;
SoundEffect Sound::Effect::menuOpen;
SoundEffect Sound::Effect::menuSelect;

SoundEffect Sound::Effect::swordCharge;
SoundEffect Sound::Effect::swordSlash1;
SoundEffect Sound::Effect::swordSpin;
SoundEffect Sound::Effect::swordTap;

SoundEffect Sound::Effect::textLetter;

void Sound::init() {
	Sound::Music::init();
	
	Sound::Effect::init();
}

void Sound::Music::init() {
	indoor.open("audio/music/indoor.ogg");
	plain.open("audio/music/plain.ogg");
	underground.open("audio/music/underground.ogg");
}

void Sound::Effect::init() {
	chest.load("audio/effects/chest.wav");
	
	dialogContinue.load("audio/effects/dialogContinue.wav");
	
	getHeart.load("audio/effects/getHeart.wav");
	getRupee.load("audio/effects/getRupee.wav");
	getRupees5.load("audio/effects/getRupees5.wav");
	
	grassDestroy.load("audio/effects/grassDestroy.wav");
	
	itemNew.load("audio/effects/itemNew.wav");
	
	mapStairs.load("audio/effects/mapStairs.wav");
	
	menuClose.load("audio/effects/menuClose.wav");
	menuCursor.load("audio/effects/menuCursor.wav");
	menuOpen.load("audio/effects/menuOpen.wav");
	menuSelect.load("audio/effects/menuSelect.wav");
	
	swordCharge.load("audio/effects/swordCharge.wav");
	swordSlash1.load("audio/effects/swordSlash1.wav");
	swordSpin.load("audio/effects/swordSpin.wav");
	swordTap.load("audio/effects/swordTap.wav");
	
	textLetter.load("audio/effects/textLetter.wav");
}

