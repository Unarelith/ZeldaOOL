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

sf::Music Sound::Music::plain;

sf::SoundBuffer Sound::Effect::chestBuffer;
sf::Sound Sound::Effect::chest;

void Sound::init() {
	Sound::Music::init();
	
	Sound::Effect::init();
}

void Sound::Music::init() {
	plain.openFromFile("audio/music/plain.ogg");
	plain.setLoop(true);
}

void Sound::Effect::init() {
	chestBuffer.loadFromFile("audio/effects/chest.wav");
	chest.setBuffer(chestBuffer);
}

