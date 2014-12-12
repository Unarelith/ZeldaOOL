/*
 * =====================================================================================
 *
 *       Filename:  Camera.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2014 06:27:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Camera.hpp"
#include "GamePad.hpp"
#include "GLUtilities.hpp"
#include "Player.hpp"

Camera::Camera() {
	m_x = Player::getInstance().getPosition().x / 16 + 0.5;
	m_y = 2;
	m_z = Player::getInstance().getPosition().y / 16 + 0.5;
	
	//m_angleH = 0.0;
	if(Player::getInstance().direction() == Movable::Direction::Left) {
		m_angleH = -180.0f;
	}
	else if(Player::getInstance().direction() == Movable::Direction::Right) {
		m_angleH = 0.0f;
	}
	else if(Player::getInstance().direction() == Movable::Direction::Up) {
		m_angleH = -90.0f;
	}
	else if(Player::getInstance().direction() == Movable::Direction::Down) {
		m_angleH = 90.0f;
	}
	
	m_angleV = 0.0;
	
	m_vx = 0;
	m_vz = 0;
}

Camera::~Camera() {
	Player::getInstance().setPosition(m_x * 16 - 8, m_z * 16 - 8);
	
	if(m_angleH >= -45 && m_angleH < 45) {
		Player::getInstance().setDirection(Movable::Direction::Right);
	}
	else if(m_angleH >= -135 && m_angleH < -45) {
		Player::getInstance().setDirection(Movable::Direction::Up);
	}
	else if(m_angleH >= 135 && m_angleH < -135) {
		Player::getInstance().setDirection(Movable::Direction::Left);
	}
	else if(m_angleH >= 45 && m_angleH < 135) {
		Player::getInstance().setDirection(Movable::Direction::Down);
	}
}

void Camera::turnH(float angle) {
	m_angleH += angle;
	
	while(m_angleH >= 180.0) {
		m_angleH -= 360.0;
	}
	while(m_angleH < -180.0) {
		m_angleH += 360.0;
	}
}

void Camera::turnV(float angle) {
	m_angleV += angle;
	
	if(89.9 < m_angleV) {
		m_angleV = 89.9;
	}
	else if(-89.9 > m_angleV) {
		m_angleV = -89.9;
	}
}

void Camera::move(float direction) {
	direction += m_angleH;
	
	m_vx = 0.04f * cos(direction * M_PI / 180.0);
	m_vz = 0.04f * sin(direction * M_PI / 180.0);
	
	m_x += m_vx;
	m_z += m_vz;
	
	m_vx = 0;
	m_vz = 0;
}

void Camera::processInputs() {
	if(GamePad::getInstance().isKeyPressed(GamePad::A)) {
		turnV(1);
		update();
	}
	else if(GamePad::getInstance().isKeyPressed(GamePad::B)) {
		turnV(-1);
		update();
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Left)) {
		turnH(-1);
		update();
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Right)) {
		turnH(1);
		update();
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Start)) {
		m_y += 0.01;
		update();
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Up)) {
		move(0.0f);
		update();
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Down)) {
		move(180.0f);
		update();
	}
}

void Camera::update() {
	glLoadIdentity();
	
	GLUtilities::lookAt(m_x, m_y, m_z,
						pointTargetedX(), pointTargetedY(), pointTargetedZ(),
						0, 1, 0);
}

