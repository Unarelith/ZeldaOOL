/*
 * =====================================================================================
 *
 *       Filename:  Sword.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:26:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GrassObject.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "PlayerState.hpp"
#include "StandingState.hpp"
#include "Sword.hpp"
#include "SwordState.hpp"
#include "TilesInfos.hpp"

Sword::Sword() : Weapon("animations-sword", 1, 16, 16) {
	std::vector<std::vector<std::pair<s16, s16>>> swordPosition = {
		{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}, { -1,  14}},
		{{ -5, -15}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}, { 12,   1}},
		{{  5, -15}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}, {-12,   1}},
		{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}, {  0, -11}}
	};
	
	std::vector<std::pair<s16, s16>> spinAttackPosition = {
		{ -1,  16}, {-12,  12}, {-15,  1}, {-12, -12},
		{  0, -15}, { 11, -12}, { 15,  2}, { 13,  13}
	};

	// Swinging
	addAnimation({0, 4, 4,  8,  8,  8,  8}, swordPosition[0], 40);
	addAnimation({1, 5, 5,  9,  9,  9,  9}, swordPosition[1], 40);
	addAnimation({2, 6, 6, 10, 10, 10, 10}, swordPosition[2], 40);
	addAnimation({3, 5, 5, 11, 11, 11, 11}, swordPosition[3], 40);
	
	// Loading
	addAnimation({12,  8}, {swordPosition[0][6], swordPosition[0][6]}, 60);
	addAnimation({13,  9}, {swordPosition[1][6], swordPosition[1][6]}, 60);
	addAnimation({14, 10}, {swordPosition[2][6], swordPosition[2][6]}, 60);
	addAnimation({15, 11}, {swordPosition[3][6], swordPosition[3][6]}, 60);
	
	// SpinAttack
	addAnimation({8, 4, 10, 6, 11, 5, 9, 7}, spinAttackPosition, 50);
	
	addCollisionHandler([this]{ Map::currentMap->scene().checkCollisionsFor(this); });
}

void Sword::reset() {
	m_state = State::Swinging;
	
	m_loadingTimer.reset();
	m_loaded = false;
	
	m_spinTimer.reset();
	m_spinCurrentFrame = 0;
	m_spinFrameCounter = 0;
	
	m_keyReleased = false;
	
	for(u8 i = 0 ; i < 9 ; i++) {
		getAnimation(i).reset();
	}
	
	m_x = -100;
	m_y = -100;
}

void Sword::update() {
	switch(m_state) {
		case State::Swinging:
			if(currentAnimation().isFinished()) {
				m_state = State::Loading;
				
				m_loadingTimer.reset();
				m_loadingTimer.start();
				
				m_player.lockDirection();
			}
			
			if(!keyPressed()) {
				m_keyReleased = true;
			}
			else if(m_keyReleased && getAnimation(m_player.direction()).framesDisplayed() >= 4) {
				if(GamePad::isKeyPressed(GameKey::Left)) {
					m_player.setDirection(Character::Direction::Left);
				}
				
				if(GamePad::isKeyPressed(GameKey::Right)) {
					m_player.setDirection(Character::Direction::Right);
				}
				
				if(GamePad::isKeyPressed(GameKey::Up)) {
					m_player.setDirection(Character::Direction::Up);
				}
				
				if(GamePad::isKeyPressed(GameKey::Down)) {
					m_player.setDirection(Character::Direction::Down);
				}
				
				m_keyReleased = false;
				
				AudioPlayer::playEffect("swordSlash1");
				
				m_player.getAnimation(m_player.direction() + 8).reset();
				getAnimation(m_player.direction()).reset();
			}
			
			break;
		case State::Loading:
			if(m_loadingTimer.time() > 650 && !m_loaded) {
				m_loaded = true;
				
				AudioPlayer::playEffect("swordCharge");
			}
			
			if(!keyPressed()) {
				if(m_loadingTimer.time() > 650) {
					AudioPlayer::playEffect("swordSpin");
					
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
					
					getAnimation(8).reset(m_spinCurrentFrame);
					getAnimation(8).start();
					
					m_player.getAnimation(12).reset(m_spinCurrentFrame);
					m_player.getAnimation(12).start();
				} else {
					m_player.setNextState<StandingState>();
				}
			}
			break;
		case State::SpinAttack:
			if(m_spinFrameCounter < 9) {
				if(m_spinCurrentFrame != getAnimation(8).framesDisplayed()) {
					m_spinCurrentFrame = getAnimation(8).framesDisplayed();
					
					m_spinFrameCounter++;
				}
			} else {
				getAnimation(8).stop();
				
				m_player.getAnimation(12).stop();
				m_player.setCurrentAnimation(m_player.direction());
				
				m_spinTimer.start();
				
				if(m_spinTimer.time() >= getAnimation(8).delay()) {
					m_player.setNextState<StandingState>();
				}
			}
			
			break;
		default:
			break;
	}
	
	Movable::testCollisions();
}

void Sword::draw() {
	m_x = m_player.x();
	m_y = m_player.y();
	
	switch(m_state) {
		case State::Swinging:
			playAnimation(m_x, m_y, m_player.direction());
			
			break;
		case State::Loading:
			if(!m_loaded) {
				drawAnimationFrame(m_x, m_y, m_player.direction() + 4, 1);
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
		
		float x = m_x + 8 + currentAnimation().currentPosition().first;
		float y = m_y + 8 + currentAnimation().currentPosition().second;
		
		if(Map::currentMap->scene().objectAtPosition(grass, x, y)) {
			if(((m_state == Sword::State::Swinging && getAnimation(m_player.direction()).framesDisplayed() > 2)
			  || m_state == Sword::State::SpinAttack)
			 && (Map::currentMap->isTile(x, y, TilesInfos::TileType::GrassTile)
			  || Map::currentMap->isTile(x, y, TilesInfos::TileType::LowGrassTile))) {
				grass.onEvent(Map::EventType::GrassCutted);
			}
		}
	}
}

void Sword::updateOwnerNextState() {
	m_player.setNextState<SwordState>(this);
}

