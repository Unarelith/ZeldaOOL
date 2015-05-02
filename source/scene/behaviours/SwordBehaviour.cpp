/*
 * =====================================================================================
 *
 *       Filename:  SwordBehaviour.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 17:44:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "SwordBehaviour.hpp"

#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

void SwordBehaviour::action(SceneObject &object) {
	auto &lifetimeComponent = object.get<LifetimeComponent>();
	Sprite &sprite = object.get<SpriteComponent>().sprite;
	
	SceneObject &owner = object.get<WeaponComponent>().owner;
	auto &ownerPosition = owner.get<PositionComponent>();
	auto &ownerSprite = owner.get<SpriteComponent>().sprite;
	
	switch(m_state) {
		case State::Swinging:
			if(sprite.currentAnimation().isFinished()) {
				m_state = State::Loading;
				
				m_loadingTimer.reset();
				m_loadingTimer.start();
				
				// m_player.lockDirection();
			}
			
			//if(!keyPressed()) {
			if(GamePad::isKeyPressed(GameKey::A)) {
				m_keyReleased = true;
			}
			else if(m_keyReleased && sprite.getAnimation((s8)ownerPosition.direction).framesDisplayed() >= 4) {
				if(GamePad::isKeyPressed(GameKey::Left)) {
					ownerPosition.direction = Direction::Left;
				}
				
				if(GamePad::isKeyPressed(GameKey::Right)) {
					ownerPosition.direction = Direction::Right;
				}
				
				if(GamePad::isKeyPressed(GameKey::Up)) {
					ownerPosition.direction = Direction::Up;
				}
				
				if(GamePad::isKeyPressed(GameKey::Down)) {
					ownerPosition.direction = Direction::Down;
				}
				
				m_keyReleased = false;
				
				AudioPlayer::playEffect("swordSlash1");
				
				ownerSprite.getAnimation((s8)ownerPosition.direction + 8).reset();
				sprite.getAnimation((s8)ownerPosition.direction).reset();
			}
			
			break;
		case State::Loading:
			if(m_loadingTimer.time() > 650 && !m_isLoaded) {
				m_isLoaded = true;
				
				AudioPlayer::playEffect("swordCharge");
			}
			
			//if(!keyPressed()) {
			if(!GamePad::isKeyPressed(GameKey::A)) {
				if(m_loadingTimer.time() > 650) {
					AudioPlayer::playEffect("swordSpin");
					
					m_isLoaded = false;
					
					m_state = State::SpinAttack;
					
					if(ownerPosition.direction == Direction::Left) {
						m_spinCurrentFrame = 2;
					}
					else if(ownerPosition.direction == Direction::Right) {
						m_spinCurrentFrame = 6;
					}
					else if(ownerPosition.direction == Direction::Up) {
						m_spinCurrentFrame = 4;
					}
					else if(ownerPosition.direction == Direction::Down) {
						m_spinCurrentFrame = 0;
					}
					
					sprite.getAnimation(8).reset(m_spinCurrentFrame);
					sprite.getAnimation(8).start();
					
					ownerSprite.getAnimation(12).reset(m_spinCurrentFrame);
					ownerSprite.getAnimation(12).start();
				} else {
					lifetimeComponent.kill();
					//m_player.setNextState<StandingState>();
				}
			}
			break;
		case State::SpinAttack:
			if(m_spinFrameCounter < 9) {
				if(m_spinCurrentFrame != sprite.getAnimation(8).framesDisplayed()) {
					m_spinCurrentFrame = sprite.getAnimation(8).framesDisplayed();
					
					m_spinFrameCounter++;
				}
			} else {
				sprite.getAnimation(8).stop();
				
				ownerSprite.getAnimation(12).stop();
				ownerSprite.setCurrentAnimation((s8)ownerPosition.direction);
				
				m_spinTimer.start();
				
				if(m_spinTimer.time() >= sprite.getAnimation(8).delay()) {
					lifetimeComponent.kill();
					// m_player.setNextState<StandingState>();
				}
			}
			
			break;
	}
	
	// Movable::testCollisions();
	
	updateSprite(object);
}

void SwordBehaviour::updateSprite(SceneObject &object) {
	auto &spriteComponent = object.get<SpriteComponent>();
	
	auto &ownerPosition = object.get<WeaponComponent>().owner.get<PositionComponent>();
	
	switch(m_state) {
		case State::Swinging:
			spriteComponent.isAnimated = true;
			spriteComponent.animID = static_cast<s8>(ownerPosition.direction);
			break;
		case State::Loading:
			spriteComponent.isAnimated = m_isLoaded;
			spriteComponent.animID = static_cast<s8>(ownerPosition.direction) + 4;
			spriteComponent.frameID = 1;
			break;
		case State::SpinAttack:
			spriteComponent.isAnimated = true;
			spriteComponent.animID = 8;
			break;
	}
}

