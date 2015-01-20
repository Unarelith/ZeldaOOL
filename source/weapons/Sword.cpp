/*
 * =====================================================================================
 *
 *       Filename:  Sword.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:26:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GrassObject.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "MapHelper.hpp"
#include "PlayerState.hpp"
#include "SoundEffect.hpp"
#include "StandingState.hpp"
#include "Sword.hpp"
#include "SwordState.hpp"
#include "TilesData.hpp"

s16 swordPosition[4][7][2] = {
	{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
	{{ -5, -15}, {  8, -12}, {  8, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
	{{  5, -15}, { -8, -12}, { -8, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
	{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
};

s16 spinAttackPosition[8][2] = {
	{-1, 16}, {-12, 12}, {-15, 1}, {-12, -12}, {0, -15}, {11, -12}, {15, 2}, {13, 13}
};

Sword::Sword() : Weapon("animations-sword", 1, 16, 16) {
	// Swinging
	addAnimation({0, 4, 4, 8, 8, 8}, 40);
	addAnimation({1, 5, 5, 9, 9, 9}, 40);
	addAnimation({2, 6, 6, 10, 10, 10}, 40);
	addAnimation({3, 5, 5, 11, 11, 11}, 40);
	
	// Loading
	addAnimation({12, 8}, 60);
	addAnimation({13, 9}, 60);
	addAnimation({14, 10}, 60);
	addAnimation({15, 11}, 60);
	
	// SpinAttack
	addAnimation({8, 4, 10, 6, 11, 5, 9, 7}, 50);
	
	addCollisionHandler([this]{ Map::currentMap->checkCollisionsFor(this); });
}

void Sword::reset() {
	m_state = State::Swinging;
	
	m_loadingTimer.reset();
	m_loaded = false;
	
	m_spinTimer.reset();
	m_spinCurrentFrame = 0;
	m_spinFrameCounter = 0;
	
	m_keyReleased = false;
	
	resetAnimation(0);
	resetAnimation(1);
	resetAnimation(2);
	resetAnimation(3);
	
	resetAnimation(4);
	resetAnimation(5);
	resetAnimation(6);
	resetAnimation(7);
	
	resetAnimation(8);
	
	m_x = -100;
	m_y = -100;
}

void Sword::update() {
	switch(m_state) {
		case State::Swinging:
			if(animationAtEnd(m_player.direction())) {
				m_state = State::Loading;
				
				m_loadingTimer.reset();
				m_loadingTimer.start();
				
				m_player.lockDirection();
			}
			
			if(!keyPressed()) {
				m_keyReleased = true;
			}
			else if(m_keyReleased && animationCurrentFrame(m_player.direction()) >= 4) {
				if(m_player.direction() == Character::Direction::Left) {
					m_player.move(4, 0);
				}
				else if(m_player.direction() == Character::Direction::Right) {
					m_player.move(-4, 0);
				}
				else if(m_player.direction() == Character::Direction::Up) {
					m_player.move(0, 3);
				}
				else if(m_player.direction() == Character::Direction::Down) {
					m_player.move(0, -3);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Left)) {
					m_player.setDirection(Character::Direction::Left);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Right)) {
					m_player.setDirection(Character::Direction::Right);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Up)) {
					m_player.setDirection(Character::Direction::Up);
				}
				
				if(Keyboard::isKeyPressed(Keyboard::Down)) {
					m_player.setDirection(Character::Direction::Down);
				}
				
				m_keyReleased = false;
				
				SoundEffect::play("swordSlash1");
				
				m_player.resetAnimation(m_player.direction() + 8);
				resetAnimation(m_player.direction());
			}
			
			break;
		case State::Loading:
			if(m_loadingTimer.time() > 650 && !m_loaded) {
				m_loaded = true;
				
				SoundEffect::play("swordCharge");
			}
			
			if(!keyPressed()) {
				if(m_loadingTimer.time() > 650) {
					SoundEffect::play("swordSpin");
					
					m_loaded = false;
					
					m_state = State::SpinAttack;
					
					if(m_player.direction() == Character::Direction::Left) {
						m_spinCurrentFrame = 2;
					}
					else if(m_player.direction() == Character::Direction::Right) {
						m_spinCurrentFrame = 6;
					}
					else if(m_player.direction() == Character::Direction::Up) {
						m_spinCurrentFrame = 4;
					}
					else if(m_player.direction() == Character::Direction::Down) {
						m_spinCurrentFrame = 0;
					}
					
					resetAnimation(8, m_spinCurrentFrame);
					startAnimation(8);
					
					m_player.resetAnimation(12, m_spinCurrentFrame);
					m_player.startAnimation(12);
				} else {
					m_player.setNextState<StandingState>();
				}
			}
			break;
		case State::SpinAttack:
			if(m_spinFrameCounter < 9) {
				if(m_spinCurrentFrame != animationCurrentFrame(8)) {
					m_spinCurrentFrame = animationCurrentFrame(8);
					
					m_spinFrameCounter++;
				}
			} else {
				m_animations[8].timer.stop();
				
				m_spinTimer.start();
				
				if(m_spinTimer.time() >= m_animations[8].delay) {
					if(m_player.direction() == Character::Direction::Left) {
						m_player.move(4, 0);
					}
					else if(m_player.direction() == Character::Direction::Right) {
						m_player.move(-4, 0);
					}
					else if(m_player.direction() == Character::Direction::Up) {
						m_player.move(0, 3);
					}
					else if(m_player.direction() == Character::Direction::Down) {
						m_player.move(0, -3);
					}
					
					m_player.setNextState<StandingState>();
				}
			}
			
			break;
		default:
			break;
	}
	
	updatePosition();
	
	Movable::testCollisions();
}

void Sword::updatePosition() {
	switch(m_state) {
		case State::Swinging:
			m_x = m_player.x() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][0];
			m_y = m_player.y() + swordPosition[m_player.direction()][animationCurrentFrame(m_player.direction())][1];
			
			break;
		case State::Loading:
			m_x = m_player.x() + swordPosition[m_player.direction()][6][0];
			m_y = m_player.y() + swordPosition[m_player.direction()][6][1];
			
			break;
		case State::SpinAttack:
			m_x = m_player.x() + spinAttackPosition[animationCurrentFrame(8)][0];
			m_y = m_player.y() + spinAttackPosition[animationCurrentFrame(8)][1];
			
			break;
		default:
			break;
	}
}

void Sword::draw() {
	// FIXME: This is here to update sword position during ScrollingTransition
	updatePosition();
	
	switch(m_state) {
		case State::Swinging:
			playAnimation(m_x, m_y, m_player.direction());
			
			break;
		case State::Loading:
			if(!m_loaded) {
				drawFrame(m_x, m_y, m_player.direction() + 8);
			} else {
				playAnimation(m_x, m_y, m_player.direction() + 4);
			}
			
			break;
		case State::SpinAttack:
			playAnimation(m_x, m_y, 8);
			
			break;
		default:
			break;
	}
}

void Sword::collisionAction(MapObject &object) {
	if(object.checkType<Enemy>()) {
		Enemy &enemy = static_cast<Enemy&>(object);
		if(enemy.isDead()) return;
		
		if(!enemy.hurt()) {
			s16 vx = enemy.x() - m_player.x();
			s16 vy = enemy.y() - m_player.y();
			
			if(vx != 0) vx /= abs(vx);
			if(vy != 0) vy /= abs(vy);
			
			if(m_state == State::SpinAttack) {
				enemy.hurt(m_strength * 2, vx, vy);
			} else {
				enemy.hurt(m_strength, vx, vy);
			}
		}
	}
	else if(object.checkType<GrassObject>()) {
		GrassObject &grass = static_cast<GrassObject&>(object);
		
		if(Map::currentMap->objectAtPosition(grass, m_x + 8, m_y + 8)) {
			if(((m_state == Sword::State::Swinging && animationCurrentFrame(m_player.direction()) > 2)
			  || m_state == Sword::State::SpinAttack)
			 && (MapHelper::isTile(m_x + 8, m_y + 8, TilesData::TileType::GrassTile)
			  || MapHelper::isTile(m_x + 8, m_y + 8, TilesData::TileType::LowGrassTile))) {
				grass.onEvent(Map::EventType::GrassCutted);
			}
		}
	}
}

void Sword::updateOwnerNextState() {
	m_player.setNextState<SwordState>(this);
}

